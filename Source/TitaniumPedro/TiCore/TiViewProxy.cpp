/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiCore/TiViewProxy.h"
#include <collection.h>
#include "Modules/Blob/TiBlob.h"
#include <ppltasks.h>

namespace Ti {

	JSStaticFunction const ViewProxy::ClassMethods[] = {
			{ "setColor", _setColor, 0 },
			{ "getSize", _getSize, 0 },
			{ "getRect", _getRect, 0 },
			{ "show", _show, 0 },
			{ "hide", _hide, 0 },
			{ "setWidth", _setWidth, 0 },
			{ "setHeight", _setHeight, 0 },
			{ "setTop", _setTop, 0 },
			{ "setBottom", _setBottom, 0 },
			{ "setRight", _setRight, 0 },
			{ "setLeft", _setLeft, 0 },
			{ "setLayout", _setLayout, 0 },
			{ "setCenter", _setCenter, 0 },
			{ "setBackgroundColor", _setBackgroundColor, 0 },
			{ "setBorderColor", _setBorderColor, 0 },
			{ "setBorderWidth", _setBorderWidth, 0 },
			{ "toImage", _toImage, 0 },
			// let's keep these private and do the work in JS,
			// create a js children array, add or remove the child,
			// then call these
			{ "_addView", _addView, 0 },
			{ "_removeView", _removeView, 0 },
			{ 0, 0, 0 }
	};
	ViewProxy::~ViewProxy() {
		component_->SizeChanged -= size_change_event_;
		component_->Loaded -= loaded_event_;

		delete layout_node_;
		component_ = nullptr;
	}

	Ti::Value ViewProxy::getRect(const std::vector<Ti::Value>& args){
		Ti::Value r;
		r.setProperty("x", Ti::Value(oldRect.x));
		r.setProperty("y", Ti::Value(oldRect.y));
		r.setProperty("width", Ti::Value(oldRect.width));
		r.setProperty("height", Ti::Value(oldRect.height));
		return r;
	}

	Ti::Value ViewProxy::show(const std::vector<Ti::Value>& args) {
		getComponent()->Visibility = Windows::UI::Xaml::Visibility::Visible;
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::hide(const std::vector<Ti::Value>& args) {
		getComponent()->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::getSize(const std::vector<Ti::Value>& args) {
		Ti::Value val;
		val.setProperty("x", Ti::Value(Windows::UI::Xaml::Controls::Canvas::GetLeft(component_)));
		val.setProperty("y", Ti::Value(Windows::UI::Xaml::Controls::Canvas::GetTop(component_)));
		val.setProperty("width", Ti::Value(component_->ActualWidth));
		val.setProperty("height", Ti::Value(component_->ActualHeight));
		return val;
	}
	Ti::Value ViewProxy::setBorderColor(const std::vector<Ti::Value>& args) {
		if (is_control_) {
			auto control = safe_cast<Windows::UI::Xaml::Controls::Control^>(getComponent());
			control->BorderBrush = ref new Windows::UI::Xaml::Media::SolidColorBrush(Ti::WebColor::Color(args[0].toString()));
		}
		else {
			OutputDebugStringW(L"[WARN] Cannot apply borderColor to this component");
		}
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setBorderWidth(const std::vector<Ti::Value>& args) {
		if (is_control_) {
			auto control = safe_cast<Windows::UI::Xaml::Controls::Control^>(getComponent());
			control->BorderThickness = args[0].toDouble();
		}
		else {
			OutputDebugStringW(L"[WARN] Cannot apply borderWidth to this component");
		}
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setColor(const std::vector<Ti::Value>& args) {
		if (is_control_) {
			auto color = args[0].toString();
			auto control = safe_cast<Windows::UI::Xaml::Controls::Control^>(getComponent());
			control->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(Ti::WebColor::Color(color));
		}
    else {
      OutputDebugStringW(L"[WARN] Cannot apply color to this component");
    }
		return Ti::Value::Undefined();
	}


	// Called from the JavaScript
	Ti::Value ViewProxy::addView(const std::vector<Ti::Value>& args) {
		// Only subclasses of Panel can take children
		auto nativeView = dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(getComponent());
		// TODO: Log something
		if (nativeView == nullptr) {
			OutputDebugStringW(L"[ERROR] ViewProxy::addView() nativeView == nullptr - RETURN");
			return Ti::Value::Undefined();
		}
		auto newView = std::dynamic_pointer_cast<ViewProxy>(toProxy(args[0]));
		auto nativeChildView = dynamic_cast<Windows::UI::Xaml::FrameworkElement^>(newView->getComponent());
		if (nativeChildView != nullptr) {
			// Tell the layout engine about this child
			Ti::Layout::nodeAddChild(layout_node_, newView->layout_node_);
			if (isLoaded()) {
				auto root = Ti::Layout::nodeRequestLayout(layout_node_);
				if (root) {
					Ti::Layout::nodeLayout(root);
				}
			}
			// Add the child to the native control
			nativeView->Children->Append(nativeChildView);
		}
		else {
			OutputDebugStringW(L"[ERROR] cannot add view to view (nativeChildView != nullptr)");

		}
		return Ti::Value::Undefined();
	}

	// Removed a view from the view
	// Reverse of the addView
	Ti::Value ViewProxy::removeView(const std::vector<Ti::Value>& args) {
		const auto nativeView = dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(getComponent());
		if (nativeView == nullptr) {
			return Ti::Value::Undefined();
		}

		auto newView = std::dynamic_pointer_cast<ViewProxy>(toProxy(args[0]));
		const auto nativeChildView = dynamic_cast<Windows::UI::Xaml::FrameworkElement^>(newView->getComponent());
		if (nativeChildView != nullptr) {
			unsigned int index = 0;
			auto children = nativeView->Children;
			auto exists = children->IndexOf(nativeChildView, &index);
			if (exists) {
				nativeView->Children->RemoveAt(index);
				Ti::Layout::nodeRemoveChild(layout_node_, newView->layout_node_);
				if (isLoaded()) {
					auto root = Ti::Layout::nodeRequestLayout(layout_node_);
					if (root) {
						Ti::Layout::nodeLayout(root);
					}
				}
			}
		}
		return Ti::Value::Undefined();
	}

	// Events!
	Ti::Value ViewProxy::eventAdded(const std::vector<Ti::Value>& args) {
		using namespace Windows::UI::Xaml::Input;
		using namespace Windows::UI::Xaml;

		auto event = args[0].toString();
		if (event == Ti::Constants::EventClick) {
			if (click_event_count_ == 0) {
				auto weak = get_weak_ptr_for_proxy();
				click_event_ = getComponent()->Tapped += ref new TappedEventHandler([weak](Platform::Object ^ sender, TappedRoutedEventArgs ^ e) {
					auto proxy = weak.lock();
					assert(proxy != nullptr);
					auto component = safe_cast<FrameworkElement^>(sender);
					auto position = e->GetPosition(component);

					Ti::Value eventArgs;
					eventArgs.setProperty("x", Ti::Value(position.X));
					eventArgs.setProperty("y", Ti::Value(position.Y));
					proxy->fireEvent(Ti::Constants::EventClick, eventArgs);
				});
			}
			++click_event_count_;
			return Ti::Proxy::eventAdded(args);
		}
		else if (event == Ti::Constants::EventTouchStart) {
			if (touch_start_event_count_ == 0) {
				getComponent()->ManipulationMode = ManipulationModes::All;
				auto weak = get_weak_ptr_for_proxy();
				touch_start_event_ = getComponent()->ManipulationStarted += ref new ManipulationStartedEventHandler([weak](Platform::Object ^ sender, ManipulationStartedRoutedEventArgs ^ e) {
					auto proxy = weak.lock();
					assert(proxy != nullptr);

					Ti::Value eventArgs;
					eventArgs.setProperty("x", Ti::Value(e->Position.X));
					eventArgs.setProperty("y", Ti::Value(e->Position.Y));
					proxy->fireEvent(Ti::Constants::EventTouchStart, eventArgs);
				});
			}
			++touch_start_event_count_;
			return Ti::Proxy::eventAdded(args);
		}
		else if (event == Ti::Constants::EventTouchMove) {
			if (touch_move_event_count_ == 0) {
				getComponent()->ManipulationMode = ManipulationModes::All;
				auto weak = get_weak_ptr_for_proxy();
				touch_move_event_ = getComponent()->ManipulationDelta += ref new ManipulationDeltaEventHandler([weak](Platform::Object ^ sender, ManipulationDeltaRoutedEventArgs ^ e) {
					auto proxy = weak.lock();
					assert(proxy != nullptr);

					Ti::Value delta;
					delta.setProperty("x", Ti::Value(e->Delta.Translation.X));
					delta.setProperty("y", Ti::Value(e->Delta.Translation.Y));

					Ti::Value eventArgs;
					eventArgs.setProperty("x", Ti::Value(e->Position.X));
					eventArgs.setProperty("y", Ti::Value(e->Position.Y));
					eventArgs.setProperty("delta", delta);

					proxy->fireEvent(Ti::Constants::EventTouchMove, eventArgs);
				});
			}
			++touch_move_event_count_;
			return Ti::Proxy::eventAdded(args);
		}
		else if (event == Ti::Constants::EventTouchEnd) {
			if (touch_end_event_count_ == 0) {
				getComponent()->ManipulationMode = ManipulationModes::All;
				auto weak = get_weak_ptr_for_proxy();
				touch_end_event_ = getComponent()->ManipulationCompleted += ref new ManipulationCompletedEventHandler([weak](Platform::Object ^ sender, ManipulationCompletedRoutedEventArgs ^ e) {
					auto proxy = weak.lock();
					assert(proxy != nullptr);

					Ti::Value eventArgs;
					eventArgs.setProperty("x", Ti::Value(e->Position.X));
					eventArgs.setProperty("y", Ti::Value(e->Position.Y));
					proxy->fireEvent(Ti::Constants::EventTouchEnd, eventArgs);
				});
			}
			++touch_end_event_count_;
			return Ti::Proxy::eventAdded(args);

		}
		else if (event == Ti::Constants::EventPostLayout) {
			post_layout_event_count_++;
		}

		return Ti::Proxy::eventAdded(args);
	}

	// Remove the events that we added, if we did add them
	Ti::Value ViewProxy::eventRemoved(const std::vector<Ti::Value>& args) {
		const std::string arg = args[0].toString();
		if (arg == Ti::Constants::EventClick) {
			--click_event_count_;
			if (click_event_count_ == 0) {
				getComponent()->Tapped -= click_event_;
			}
			return Ti::Proxy::eventRemoved(args);
		}
		else if (arg == Ti::Constants::EventTouchStart) {
			--touch_start_event_count_;
			if (touch_start_event_count_ == 0) {
				getComponent()->ManipulationStarted -= touch_start_event_;
			}
			return Ti::Proxy::eventRemoved(args);
		}
		else if (arg == Ti::Constants::EventTouchMove) {
			--touch_move_event_count_;
			if (touch_move_event_count_ == 0) {
				getComponent()->ManipulationDelta -= touch_move_event_;
			}
			return Ti::Proxy::eventRemoved(args);
		}
		else if (arg == Ti::Constants::EventTouchEnd) {
			--touch_end_event_count_;
			if (touch_end_event_count_ == 0) {
				getComponent()->ManipulationCompleted -= touch_end_event_;
			}
			return Ti::Proxy::eventRemoved(args);
		}
		else if (arg == Ti::Constants::EventPostLayout) {
			--post_layout_event_count_;
		}

		return Ti::Proxy::eventRemoved(args);
	}

	// Setting the background color is tricky, there are only two types of
	// base controls that take this property, the Control and the Panel.
	Ti::Value ViewProxy::setBackgroundColor(const std::vector<Ti::Value>& args) {
		auto bgColor = args[0].toString();
		if (is_control_) {
			auto control = safe_cast<Windows::UI::Xaml::Controls::Control^>(getComponent());
			control->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(Ti::WebColor::Color(bgColor));
			return Ti::Value::Undefined();
		}
		if (is_panel_) {
			auto panel = safe_cast<Windows::UI::Xaml::Controls::Panel^>(getComponent());
			panel->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(Ti::WebColor::Color(bgColor));
			return Ti::Value::Undefined();
		}
		return Ti::Value::Undefined();
	}

	static void onLayoutCallback(Ti::Layout::Node* node)
	{
		auto proxy = static_cast<ViewProxy*>(node->data);
		auto rect = Layout::RectMake(node->element.measuredLeft, node->element.measuredTop, node->element.measuredWidth, node->element.measuredHeight);
		proxy->onLayoutEngineCallback(rect, node->name);
	}

	void ViewProxy::setComponent(Windows::UI::Xaml::FrameworkElement^ component)
	{
		using namespace Windows::UI::Xaml;
		using namespace Windows::UI::Xaml::Controls;
		assert(component_ == nullptr);
		component_ = component;
		is_panel_ = dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(component_) != nullptr;
		is_control_ = dynamic_cast<Windows::UI::Xaml::Controls::Control^>(component_) != nullptr;
		loaded_event_ = component_->Loaded += ref new RoutedEventHandler([this](Platform::Object ^sender, RoutedEventArgs ^e){
			auto component = getComponent();
			auto rect = Layout::RectMake(
				Canvas::GetLeft(component),
				Canvas::GetTop(component),
				component->ActualWidth,
				component->ActualHeight
				);
			
			onComponentLoaded(rect);
		});
		size_change_event_ = component_->SizeChanged += ref new Windows::UI::Xaml::SizeChangedEventHandler([this](Platform::Object ^sender, SizeChangedEventArgs ^e){
			auto component = getComponent();
			auto rect = Layout::RectMake(
				Canvas::GetLeft(component),
				Canvas::GetTop(component),
				e->NewSize.Width,
				e->NewSize.Height
				);
			onComponentSizeChange(rect);
		});
		layout_node_ = new Layout::Node;
		layout_node_->data = this;
		layout_node_->onLayout = onLayoutCallback;

		if (defaultWidth() == Ti::Constants::SizeSIZE) {
			is_width_size_ = true;
			layout_node_->properties.defaultWidthType = Layout::ValueType::Size;
		}
		else if (defaultWidth() == Ti::Constants::SizeFILL) {
			layout_node_->properties.defaultWidthType = Layout::ValueType::Fill;
		}

		if (defaultHeight() == Ti::Constants::SizeSIZE) {
			is_height_size_ = true;
			layout_node_->properties.defaultHeightType = Layout::ValueType::Size;
		}
		else if (defaultHeight() == Ti::Constants::SizeFILL) {
			layout_node_->properties.defaultHeightType = Layout::ValueType::Fill;
		}

	}

	void ViewProxy::onLayoutEngineCallback(Layout::Rect rect, const std::string& name)
	{
		using namespace Windows::UI::Xaml::Controls;
		using namespace Windows::UI::Xaml;
		if (is_height_size_ && rect.height == 0) return;
		if (is_width_size_ && rect.width == 0) return;
		if (rect.width < 0 || rect.height < 0) return;
		if (Layout::RectIsEmpty(rect)) return;
		if (Layout::RectIsEqualToRect(oldRect, rect)) return;


		auto component = getComponent();
		auto panel = is_panel_ ? safe_cast<Panel^>(component) : nullptr;
		auto parentLayout = layout_node_->parent;

		auto setWidth = false;
		auto setHeight = false;
		auto setWidthOnWidget = !is_width_size_;
		auto setHeightOnWidget = !is_height_size_;

		if (!is_panel_ && is_width_size_ && parentLayout != nullptr) {
			if (rect.width > parentLayout->element.measuredWidth && parentLayout->element.measuredWidth > 0) {
				rect.width = parentLayout->element.measuredWidth;
				setWidthOnWidget = true;
			}
		}
		if (!is_panel_ && is_height_size_ && parentLayout != nullptr) {
			if (rect.height > parentLayout->element.measuredHeight && parentLayout->element.measuredHeight > 0) {
				rect.height = parentLayout->element.measuredHeight;
				setHeightOnWidget = true;
			}
		}

		oldRect = Layout::RectMake(rect.x, rect.y, rect.width, rect.height);
		if (is_panel_) {
			for (auto child : panel->Children) {
				child->Visibility = Visibility::Collapsed;
			}
			setWidth = true;
			setHeight = true;
		}

		if ((!is_panel_ && setWidthOnWidget) || setWidth) {
			component->Width = rect.width;
		}
		if ((!is_panel_ && setHeightOnWidget) || setHeight) {
			component->Height = rect.height;
		}

		Canvas::SetLeft(component, rect.x);
		Canvas::SetTop(component, rect.y);

		if (is_panel_) {
			for (auto child : panel->Children) {
				child->Visibility = Visibility::Visible;
			}
		}
	}
	void ViewProxy::onComponentLoaded(const Layout::Rect& rect)
	{
		is_loaded_ = true;
//		this messes up table view rows
//		if (isWindow()) {
			auto root = Ti::Layout::nodeRequestLayout(layout_node_);
			if (root) {
				Ti::Layout::nodeLayout(root);
			}
//		}
	}
	void ViewProxy::onComponentSizeChange(const Layout::Rect& rect)
	{
		bool needsLayout = false;
		if (is_width_size_ && !is_panel_) {
			layout_node_->properties.width.value = rect.width;
			layout_node_->properties.width.valueType = Ti::Layout::Fixed;
			needsLayout = isLoaded();
		}
		if (is_height_size_ && !is_panel_) {
			layout_node_->properties.height.value = rect.height;
			layout_node_->properties.height.valueType = Ti::Layout::Fixed;
			needsLayout = isLoaded();
		}
		if (needsLayout) {
			auto root = Ti::Layout::nodeRequestLayout(layout_node_);
			if (root) {
				Ti::Layout::nodeLayout(root);
			}
		}
		if (post_layout_event_count_ > 0) {
			Ti::Value val;
			val.setProperty("x", Ti::Value(rect.x));
			val.setProperty("y", Ti::Value(rect.y));
			val.setProperty("width", Ti::Value(rect.width));
			val.setProperty("height", Ti::Value(rect.height));
			fireEvent(Ti::Constants::EventPostLayout, val);
		}
	}

	void ViewProxy::setLayoutProperty(const Ti::Layout::ValueName& name, const std::string& value)
	{
		Ti::Layout::InputProperty prop;
		prop.name = name;
		prop.value = value;
		Ti::Layout::populateLayoutPoperties(prop, &layout_node_->properties, 1);
		if (isLoaded()) {
			auto root = Ti::Layout::nodeRequestLayout(layout_node_);
			if (root) {
				Ti::Layout::nodeLayout(root);
			}
		}
	}

	Ti::Value ViewProxy::setWidth(const std::vector<Ti::Value>& args)
	{
		auto width = args[0].toString();
		if (!ignoreWidth()) {
			// TODO: Deprecate "auto"
			if (width == "auto"){
				width = defaultWidth();
			}
			if (width == Ti::Constants::SizeSIZE) {
				is_width_size_ = true;
			}
			else {
				is_width_size_ = false;
			}
			setLayoutProperty(Ti::Layout::ValueName::Width, width);
		}
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setHeight(const std::vector<Ti::Value>& args)
	{
		auto height = args[0].toString();
		if (!ignoreHeight()) {
			// TODO: Deprecate "auto"
			if (height == "auto"){
				height = defaultHeight();
			}
			if (height == Ti::Constants::SizeSIZE) {
				is_height_size_ = true;
			}
			else {
				is_height_size_ = false;
			}
			setLayoutProperty(Ti::Layout::ValueName::Height, height);
		}
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setLeft(const std::vector<Ti::Value>& args)
	{
		setLayoutProperty(Ti::Layout::ValueName::Left, args[0].toString());
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setRight(const std::vector<Ti::Value>& args)
	{
		setLayoutProperty(Ti::Layout::ValueName::Right, args[0].toString());
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setTop(const std::vector<Ti::Value>& args)
	{
		setLayoutProperty(Ti::Layout::ValueName::Top, args[0].toString());
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setBottom(const std::vector<Ti::Value>& args)
	{
		setLayoutProperty(Ti::Layout::ValueName::Bottom, args[0].toString());
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setCenter(const std::vector<Ti::Value>& args)
	{
		auto obj = args[0];
		if (obj.isObject()) {
			auto x = obj.getProperty("x");
			auto y = obj.getProperty("y");
			if (!x.isUndefined()) {
				setLayoutProperty(Ti::Layout::ValueName::CenterX, x.toString());
			}
			if (!y.isUndefined()) {
				setLayoutProperty(Ti::Layout::ValueName::CenterY, y.toString());
			}
		}
		return Ti::Value::Undefined();
	}
	Ti::Value ViewProxy::setLayout(const std::vector<Ti::Value>& args)
	{
		auto layout = args[0].toString();
		if (layout == "horizontal") {
			layout_node_->element.layoutType = Layout::LayoutType::Horizontal;
		}
		else if (layout == "vertical") {
			layout_node_->element.layoutType = Layout::LayoutType::Vertical;
		}
		else {
			layout_node_->element.layoutType = Layout::LayoutType::Composite;
		}
		if (isLoaded()) {
			auto root = Ti::Layout::nodeRequestLayout(layout_node_);
			if (root) {
				Ti::Layout::nodeLayout(root);
			}
		}
		return Ti::Value::Undefined();
	}

	Ti::Value ViewProxy::toImage(const std::vector<Ti::Value>& arguments) {
		if (arguments.size() < 1) {
			std::clog << "[ERROR] toImage() does not work on Windows. Use toImage(callback) instead." << std::endl;
			return Ti::Value::Undefined();
		}
		auto callback = arguments.at(0);
		auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap();
		const auto func = std::bind([bitmap, callback](const std::weak_ptr<Ti::ViewProxy>& weakThis) {
			auto blob = Ti::Blob::Blob::create("image/png");
			blob->toImage(bitmap, [weakThis, callback](const std::shared_ptr<Ti::Blob::Blob>& blob) {
				const auto strong_ptr = weakThis.lock();
				if (strong_ptr) {
					JSValueRef args[] = { blob->toValue().JSObjectRef() };
					JSObjectCallAsFunction(Ti::Runtime::instance().globalContext(), callback.JSObjectRef(), strong_ptr->get_js_object(), 1, args, nullptr);
				}
			});
		}, std::move(get_weak_ptr_for_proxy()));
		concurrency::create_task(bitmap->RenderAsync(getComponent())).then(func);
		return Ti::Value::Undefined();
	}

} // namespace Ti

#undef TI_SET_LAYOUT_PROPERTY

/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/View.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml::Input;
		using namespace Windows::UI::Xaml;

		std::unordered_map<std::string, std::string> View::CustomFonts__;

		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::View(js_context)
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::UI::View::ctor ", this);
		}

		View::~View() 
		{
			TITANIUM_LOG_DEBUG("TitaniumWindows::UI::View::dtor ", this);
		}

		void View::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::View::postCallAsConstructor(js_context, arguments);	
			
			canvas__ = ref new Windows::UI::Xaml::Controls::Canvas();

			Titanium::UI::View::setLayoutDelegate<WindowsViewLayoutDelegate>();

			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForWidth(Titanium::UI::LAYOUT::FILL);

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(canvas__);
		}

		void View::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::UI::View>::Class());
		}

		// FIXME What file formats does windows support for fonts? We need to limit here! Most of what I read says only TTF, but I see some mentions of OpenType
		static const std::string ti_label_js = R"JS(
	this.exports = {};
	this.exports.getFontFilePath = function(fontFamily) {
		var iconsFolder = Ti.Filesystem.getFile(Ti.Filesystem.applicationDirectory, 'fonts');
		var files = iconsFolder.getDirectoryListing();
		for (var i = 0; i < files.length; i++) {
			var name = files[i];
			if (name.toLowerCase() == fontFamily.toLowerCase() || name.toLowerCase().indexOf(fontFamily.toLowerCase() + '.') == 0) {
				return name;
			}
		}
		return null;
	};
	)JS";

		Windows::UI::Xaml::Media::FontFamily^ View::LookupFont(const JSContext& js_context, const std::string& family)
		{
			auto path = family;
			if (CustomFonts__.find(family) == CustomFonts__.end()) {
				// Look up to see if this is a custom font!
				auto export_object = js_context.CreateObject();
				js_context.JSEvaluateScript(ti_label_js, export_object);
				TITANIUM_ASSERT(export_object.HasProperty("exports"));
				auto exports = export_object.GetProperty("exports");
				TITANIUM_ASSERT(exports.IsObject());
				auto exports_object = static_cast<JSObject>(exports);
				auto eval_result = exports_object.GetProperty("getFontFilePath");
				TITANIUM_ASSERT(eval_result.IsObject());
				auto func = static_cast<JSObject>(eval_result);
				TITANIUM_ASSERT(func.IsFunction());
				auto result = func(family, js_context.get_global_object());
				if (result.IsNull()) { // we have no custom font by this name, assume it's a built-in font
					path = family;
				} else {
					TITANIUM_ASSERT(result.IsString()); // custom font file
					const auto file_name = static_cast<std::string>(result);
					path = "/fonts/" + file_name + "#" + family;
				}
			}

			CustomFonts__.emplace(family, path);
			return ref new Windows::UI::Xaml::Media::FontFamily(Utility::ConvertUTF8String(path));
		}

		void View::registerNativeUIWrapHook(const std::function<JSObject(const JSContext&, const JSObject&)>& requireHook)
		{
			//
			// This is special case: Called from TitaniumWindows::Application,
			// Set layout delegate on Ti.UI.View for registering native view wrapper hook
			//
			Titanium::UI::View::setLayoutDelegate<WindowsViewLayoutDelegate>();
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->registerNativeUIWrapHook(requireHook);
		}

		Windows::UI::Xaml::FrameworkElement^ View::getComponent() TITANIUM_NOEXCEPT
		{
			return getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
		}

		void View::firePositionEvent(const std::string& event_name, FrameworkElement^ component, Windows::Foundation::Point position)
		{
			const auto ctx = get_context();

			JSObject  eventArgs = ctx.CreateObject();
			eventArgs.SetProperty("x", ctx.CreateNumber(position.X));
			eventArgs.SetProperty("y", ctx.CreateNumber(position.Y));

			this->fireEvent(event_name, eventArgs);		
		}

		void View::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::enableEvent(event_name);

			const JSContext ctx = this->get_context();
			const auto component = getComponent();

			if (event_name == "touchmove") {
				component->ManipulationMode = ManipulationModes::All;
				touchmove_event__ = component->ManipulationDelta += ref new ManipulationDeltaEventHandler([ctx, this](Platform::Object^ sender, ManipulationDeltaRoutedEventArgs^ e) {
					JSObject  delta = ctx.CreateObject();
					delta.SetProperty("x", ctx.CreateNumber(e->Delta.Translation.X));
					delta.SetProperty("y", ctx.CreateNumber(e->Delta.Translation.Y));

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("x", ctx.CreateNumber(e->Position.X));
					eventArgs.SetProperty("y", ctx.CreateNumber(e->Position.Y));
					eventArgs.SetProperty("delta", delta);

					this->fireEvent("touchmove", eventArgs);
				});
			} else if (event_name == "touchstart") {
				component->PointerPressed += ref new PointerEventHandler([ctx, this](Platform::Object^ sender, PointerRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					const auto point = Windows::UI::Input::PointerPoint::GetCurrentPoint(e->Pointer->PointerId);
					firePositionEvent("touchstart", component, point->Position);
				});
			} else if (event_name == "touchend") {
				component->PointerReleased += ref new PointerEventHandler([ctx, this](Platform::Object^ sender, PointerRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					const auto point = Windows::UI::Input::PointerPoint::GetCurrentPoint(e->Pointer->PointerId);
					firePositionEvent("touchend", component, point->Position);
				});
			} else if (event_name == "click") {
				click_event__ = component->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object^ sender, TappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("click", component, e->GetPosition(component));
				});
			} else if (event_name == "doubleclick") {
				doubleclick_event__ = component->DoubleTapped += ref new DoubleTappedEventHandler([this, ctx](Platform::Object^ sender, DoubleTappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("doubleclick", component, e->GetPosition(component));
				});
			} else if (event_name == "singletap") {
				singletap_event__ = component->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object^ sender, TappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("singletap", component, e->GetPosition(component));
				});
			} else if (event_name == "doubletap") {
				doubletap_event__ = component->DoubleTapped += ref new DoubleTappedEventHandler([this, ctx](Platform::Object^ sender, DoubleTappedRoutedEventArgs^ e) {
					const auto component = safe_cast<FrameworkElement^>(sender);
					firePositionEvent("doubletap", component, e->GetPosition(component));
				});
			} else if (event_name == "longpress") {
				longpress_event__ = component->Holding += ref new HoldingEventHandler([this, ctx](Platform::Object^ sender, HoldingRoutedEventArgs^ e) {
					// fires event only when it started
					if (e->HoldingState == Windows::UI::Input::HoldingState::Started) {
						const auto component = safe_cast<FrameworkElement^>(sender);
						firePositionEvent("longpress", component, e->GetPosition(component));
					}
				});
			} else if (event_name == "focus") {
				focus_event__ = component->GotFocus += ref new RoutedEventHandler([this, ctx](Platform::Object^ sender, RoutedEventArgs^ e) {
					this->fireEvent("focus");
				});
				return;
			}
		}

		void View::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::disableEvent(event_name);
			const auto component = getComponent();
			if (event_name == "touchmove") {
				component->ManipulationDelta -= touchmove_event__;
			} else if (event_name == "touchstart") {
				component->ManipulationStarted -= touchstart_event__;
			} else if (event_name == "touchend") {
				component->ManipulationCompleted -= touchend_event__;
			} else if (event_name == "click") {
				component->Tapped -= click_event__;
			} else if (event_name == "doubleclick") {
				component->DoubleTapped -= doubleclick_event__;
			} else if (event_name == "singletap") {
				component->Tapped -= singletap_event__;
			} else if (event_name == "doubletap") {
				component->DoubleTapped -= doubletap_event__;
			} else if (event_name == "longpress") {
				component->Holding -= longpress_event__;
			} else if (event_name == "focus") {
				component->GotFocus -= focus_event__;
			}
		}
	} // namespace UI
} // namespace TitaniumWindows

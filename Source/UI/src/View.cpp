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
#include "Titanium/Blob.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
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

		void View::ToImage(Windows::UI::Xaml::FrameworkElement^ component, JSValue callback, JSObject this_object)
		{
			const auto render = ref new Windows::UI::Core::DispatchedHandler([component, callback, this_object]() {
				auto renderTarget = ref new Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap();
				concurrency::create_task(renderTarget->RenderAsync(component)).then([renderTarget](){
					return renderTarget->GetPixelsAsync();
				}).then([callback, this_object](concurrency::task<Windows::Storage::Streams::IBuffer^> task){
					try {
						const auto buffer = task.get();
						const auto data = TitaniumWindows::Utility::GetContentFromBuffer(buffer);
						if (callback.IsObject()) {
							auto func = static_cast<JSObject>(callback);
							if (func.IsFunction()) {
								const auto blob = callback.get_context().CreateObject(JSExport<Titanium::Blob>::Class()).CallAsConstructor();
								const auto blob_ptr = blob.GetPrivate<Titanium::Blob>();
								blob_ptr->construct(data);

								const std::vector<JSValue> args = { blob };
								func(args, this_object);
							}
						}
					} catch (Platform::COMException^ e) {
						TITANIUM_LOG_WARN("ImageView.toImage: ", TitaniumWindows::Utility::ConvertString(e->Message));
					}
				});
			});

			Windows::UI::Xaml::Window::Current->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, render);
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

		std::shared_ptr<Titanium::Blob> View::toImage(JSValue callback, const bool& honorScaleFactor) TITANIUM_NOEXCEPT
		{
			if (callback.IsObject() && static_cast<JSObject>(callback).IsFunction()) {
				TitaniumWindows::UI::View::ToImage(getComponent(), callback, get_object());
			} else {
				HAL::detail::ThrowRuntimeError("View.toImage", "View.toImage only works with callback");
			}

			return nullptr;
		}
	} // namespace UI
} // namespace TitaniumWindows

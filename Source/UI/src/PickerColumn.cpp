/**
* Titanium.UI.PickerColumn for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/PickerColumn.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/UI/PickerRow.hpp"
#include <collection.h>

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Platform::Collections;
		using namespace Windows::UI::Xaml;

		PickerColumn::PickerColumn(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::PickerColumn(js_context)
		{
			TITANIUM_LOG_DEBUG("PickerColumn::ctor ", this);
		}

		PickerColumn::~PickerColumn() 
		{
			TITANIUM_LOG_DEBUG("PickerColumn::dtor ", this);
		}

		void PickerColumn::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::PickerColumn::postCallAsConstructor(js_context, arguments);

			picker__ = ref new Windows::UI::Xaml::Controls::ComboBox();

			resetPickerBinding();

			Titanium::UI::PickerColumn::setLayoutDelegate<WindowsViewLayoutDelegate>();
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(picker__);
		}

		void PickerColumn::refreshRows() 
		{
			resetPickerBinding();

			for (const auto r : rows__) {
				const auto row = std::dynamic_pointer_cast<TitaniumWindows::UI::PickerRow>(r);
				pickerItems__->Append(row->getComponent());
			}
		}

		void PickerColumn::bindPickerItemsSource() 
		{
			pickerItemsSource__->Source = pickerItems__;
		}

		void PickerColumn::unbindPickerItemsSource() 
		{
			pickerItemsSource__->Source = ref new Vector<::Platform::String^>();
		}

		void PickerColumn::resetPickerBinding() 
		{
			pickerItems__ = ref new Vector<Windows::UI::Xaml::FrameworkElement^>();

			pickerItemsSource__ = ref new Data::CollectionViewSource();
			pickerItemsSource__->Source = pickerItems__;

			auto binding = ref new Data::Binding();
			binding->Source = pickerItemsSource__;
			Data::BindingOperations::SetBinding(picker__, Controls::ComboBox::ItemsSourceProperty, binding);
		}

		void PickerColumn::JSExportInitialize()
		{
			JSExport<PickerColumn>::SetClassVersion(1);
			JSExport<PickerColumn>::SetParent(JSExport<Titanium::UI::PickerColumn>::Class());
		}

	} // namespace UI
} // namespace TitaniumWindows

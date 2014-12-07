using namespace Windows::UI::Xaml;

using namespace TitaniumRuss;

namespace Russ
{
	public ref class Me sealed
	{
		public:
		Me() {  }
	};
}

int main(Platform::Array<Platform::String^>^)
{
    Application::Start(ref new ApplicationInitializationCallback([](ApplicationInitializationCallbackParams^ params) {
                ref new TiApp();
            }));
    
    return 0;
}

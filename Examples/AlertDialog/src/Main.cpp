using namespace Windows::UI::Xaml;

using namespace TitaniumPedro;

namespace Pedro
{
	public ref class Me sealed
	{
		public:
		Me() {  }
	};
}

int main(Platform::Array<Platform::String^>^) {
    Application::Start(ref new ApplicationInitializationCallback([](ApplicationInitializationCallbackParams^ params) {
                ref new App();
            }));
    
    return 0;
}

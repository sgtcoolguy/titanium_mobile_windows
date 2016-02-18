/*
 * Just to make sure .winmd file has at least one public entry point (TIMOB-20192)
 */
namespace TitaniumWindows_Sensors
{
	public ref class TitaniumEntryPoint sealed
	{
	public:
		TitaniumEntryPoint() { };
	};
}
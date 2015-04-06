mkdir dist
mkdir dist\windows
mkdir dist\windows\doc

echo Generate docs
cd apidoc
call npm install .
echo Exit Code = %ERRORLEVEL%
call node ti_win_yaml.js
echo Exit Code = %ERRORLEVEL%
cd ..
robocopy apidoc\Titanium dist\windows\doc\Titanium /e

echo Copy over cli, templates, package.json
robocopy cli dist\windows\cli /e
robocopy templates dist\windows\templates /e
robocopy . dist\windows package.json

echo Native libraries
mkdir dist\windows\lib

echo TODO Limit to only copy dll/lib/winmd?

echo Titanium Windows Accelerometer
robocopy build\x86\Accelerometer\Release dist\windows\lib\TitaniumWindows_Accelerometer\wp\x86 TitaniumWindows_Accelerometer.*
robocopy build\store\x86\Accelerometer\Release dist\windows\lib\TitaniumWindows_Accelerometer\store\x86 TitaniumWindows_Accelerometer.*
robocopy build\ARM\Accelerometer\Release dist\windows\lib\TitaniumWindows_Accelerometer\wp\ARM TitaniumWindows_Accelerometer.*
robocopy build\x86\Accelerometer dist\windows\lib\TitaniumWindows_Accelerometer\include titaniumwindows_accelerometer_export.h

echo Titanium Windows API
robocopy build\x86\API\Release dist\windows\lib\TitaniumWindows_API\wp\x86 TitaniumWindows_API.*
robocopy build\store\x86\API\Release dist\windows\lib\TitaniumWindows_API\store\x86 TitaniumWindows_API.*
robocopy build\ARM\API\Release dist\windows\lib\TitaniumWindows_API\wp\ARM TitaniumWindows_API.*
robocopy build\x86\API dist\windows\lib\TitaniumWindows_API\include titaniumwindows_api_export.h

echo Titanium Windows App
robocopy build\x86\App\Release dist\windows\lib\TitaniumWindows_App\wp\x86 TitaniumWindows_App.*
robocopy build\store\x86\App\Release dist\windows\lib\TitaniumWindows_App\store\x86 TitaniumWindows_App.*
robocopy build\ARM\App\Release dist\windows\lib\TitaniumWindows_App\wp\ARM TitaniumWindows_App.*
robocopy build\x86\App dist\windows\lib\TitaniumWindows_App\include titaniumwindows_app_export.h

echo Titanium Windows Filesystem
robocopy build\x86\Filesystem\Release dist\windows\lib\TitaniumWindows_Filesystem\wp\x86 TitaniumWindows_Filesystem.*
robocopy build\store\x86\Filesystem\Release dist\windows\lib\TitaniumWindows_Filesystem\store\x86 TitaniumWindows_Filesystem.*
robocopy build\ARM\Filesystem\Release dist\windows\lib\TitaniumWindows_Filesystem\wp\ARM TitaniumWindows_Filesystem.*
robocopy build\x86\Filesystem dist\windows\lib\TitaniumWindows_Filesystem\include titaniumwindows_filesystem_export.h

echo Titanium Windows Gesture
robocopy build\x86\Gesture\Release dist\windows\lib\TitaniumWindows_Gesture\wp\x86 TitaniumWindows_Gesture.*
robocopy build\store\x86\Gesture\Release dist\windows\lib\TitaniumWindows_Gesture\store\x86 TitaniumWindows_Gesture.*
robocopy build\ARM\Gesture\Release dist\windows\lib\TitaniumWindows_Gesture\wp\ARM TitaniumWindows_Gesture.*
robocopy build\x86\Gesture dist\windows\lib\TitaniumWindows_Gesture\include titaniumwindows_gesture_export.h

echo Titanium Windows Global
robocopy build\x86\Global\Release dist\windows\lib\TitaniumWindows_Global\wp\x86 TitaniumWindows_Global.*
robocopy build\store\x86\Global\Release dist\windows\lib\TitaniumWindows_Global\store\x86 TitaniumWindows_Global.*
robocopy build\ARM\Global\Release dist\windows\lib\TitaniumWindows_Global\wp\ARM TitaniumWindows_Global.*
robocopy build\x86\Global dist\windows\lib\TitaniumWindows_Global\include titaniumwindows_global_export.h

echo HAL
robocopy build\x86\Global\TitaniumKit\HAL\Release dist\windows\lib\HAL\wp\x86 HAL.*
robocopy build\store\x86\Global\TitaniumKit\HAL\Release dist\windows\lib\HAL\store\x86 HAL.*
robocopy build\ARM\Global\TitaniumKit\HAL\Release dist\windows\lib\HAL\wp\ARM HAL.*
robocopy build\x86\Global\TitaniumKit\HAL dist\windows\lib\HAL\include hal_export.h

echo LayoutEngine
robocopy build\x86\LayoutEngine\Release dist\windows\lib\LayoutEngine\wp\x86 LayoutEngine.*
robocopy build\store\x86\LayoutEngine\Release dist\windows\lib\LayoutEngine\store\x86 LayoutEngine.*
robocopy build\ARM\LayoutEngine\Release dist\windows\lib\LayoutEngine\wp\ARM LayoutEngine.*
robocopy build\x86\LayoutEngine dist\windows\lib\LayoutEngine\include layoutengine_export.h

echo Titanium Windows Map
robocopy build\x86\Map\Release dist\windows\lib\TitaniumWindows_Map\wp\x86 TitaniumWindows_Map.*
robocopy build\store\x86\Map\Release dist\windows\lib\TitaniumWindows_Map\store\x86 TitaniumWindows_Map.*
robocopy build\ARM\Map\Release dist\windows\lib\TitaniumWindows_Map\wp\ARM TitaniumWindows_Map.*
robocopy build\x86\Map dist\windows\lib\TitaniumWindows_Map\include titaniumwindows_map_export.h

echo Titanium Windows Network
robocopy build\x86\Network\Release dist\windows\lib\TitaniumWindows_Network\wp\x86 TitaniumWindows_Network.*
robocopy build\store\x86\Network\Release dist\windows\lib\TitaniumWindows_Network\store\x86 TitaniumWindows_Network.*
robocopy build\ARM\Network\Release dist\windows\lib\TitaniumWindows_Network\wp\ARM TitaniumWindows_Network.*
robocopy build\x86\Network dist\windows\lib\TitaniumWindows_Network\include titaniumwindows_network_export.h

echo Titanium Windows Platform
robocopy build\x86\Platform\Release dist\windows\lib\TitaniumWindows_Platform\wp\x86 TitaniumWindows_Platform.*
robocopy build\store\x86\Platform\Release dist\windows\lib\TitaniumWindows_Platform\store\x86 TitaniumWindows_Platform.*
robocopy build\ARM\Platform\Release dist\windows\lib\TitaniumWindows_Platform\wp\ARM TitaniumWindows_Platform.*
robocopy build\x86\Platform dist\windows\lib\TitaniumWindows_Platform\include titaniumwindows_platform_export.h

echo Titanium Windows Ti
robocopy build\x86\Ti\Release dist\windows\lib\TitaniumWindows_Ti\wp\x86 TitaniumWindows_Ti.*
robocopy build\store\x86\Ti\Release dist\windows\lib\TitaniumWindows_Ti\store\x86 TitaniumWindows_Ti.*
robocopy build\ARM\Ti\Release dist\windows\lib\TitaniumWindows_Ti\wp\ARM TitaniumWindows_Ti.*
robocopy build\x86\Ti dist\windows\lib\TitaniumWindows_Ti\include titaniumwindows_ti_export.h

echo Titanium Windows
robocopy build\x86\Release dist\windows\lib\TitaniumWindows\wp\x86 TitaniumWindows.*
robocopy build\store\x86\Release dist\windows\lib\TitaniumWindows\store\x86 TitaniumWindows.*
robocopy build\ARM\Release dist\windows\lib\TitaniumWindows\wp\ARM TitaniumWindows.*
mkdir dist\windows\lib\TitaniumWindows\include

echo Titanium Kit
robocopy build\x86\Global\TitaniumKit\Release dist\windows\lib\TitaniumKit\wp\x86 TitaniumKit.*
robocopy build\store\x86\Global\TitaniumKit\Release dist\windows\lib\TitaniumKit\store\x86 TitaniumKit.*
robocopy build\ARM\Global\TitaniumKit\Release dist\windows\lib\TitaniumKit\wp\ARM TitaniumKit.*
robocopy build\x86\Global\TitaniumKit dist\windows\lib\TitaniumKit\include titaniumkit_export.h

echo Titanium Windows UI
robocopy build\x86\UI\Release dist\windows\lib\TitaniumWindows_UI\wp\x86 TitaniumWindows_UI.*
robocopy build\store\x86\UI\Release dist\windows\lib\TitaniumWindows_UI\store\x86 TitaniumWindows_UI.*
robocopy build\ARM\UI\Release dist\windows\lib\TitaniumWindows_UI\wp\ARM TitaniumWindows_UI.*
robocopy build\x86\UI dist\windows\lib\TitaniumWindows_UI\include titaniumwindows_ui_export.h

echo Titanium Windows Utility
robocopy build\x86\Global\Utility\Release dist\windows\lib\TitaniumWindows_Utility\wp\x86 TitaniumWindows_Utility.*
robocopy build\store\x86\Global\Utility\Release dist\windows\lib\TitaniumWindows_Utility\store\x86 TitaniumWindows_Utility.*
robocopy build\ARM\Global\Utility\Release dist\windows\lib\TitaniumWindows_Utility\wp\ARM TitaniumWindows_Utility.*
robocopy build\x86\Global\Utility dist\windows\lib\TitaniumWindows_Utility\include titaniumwindows_utility_export.h

echo Titanium Windows Utils
robocopy build\x86\Utils\Release dist\windows\lib\TitaniumWindows_Utils\wp\x86 TitaniumWindows_Utils.*
robocopy build\store\x86\Utils\Release dist\windows\lib\TitaniumWindows_Utils\store\x86 TitaniumWindows_Utils.*
robocopy build\ARM\Utils\Release dist\windows\lib\TitaniumWindows_Utils\wp\ARM TitaniumWindows_Utils.*
robocopy build\x86\Utils dist\windows\lib\TitaniumWindows_Utils\include titaniumwindows_utils_export.h

IF %ERRORLEVEL% LEQ 4 exit /B 0

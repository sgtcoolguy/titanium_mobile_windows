
var path = require('path'),
	fs = require('fs'),
	async = require('async'),
	colors = require('colors'),
	wrench = require('wrench'),
	spawn = require('child_process').spawn;
/**
 * @param sourceDir Where the source is
 * @param buildDir Where to build the project
 * @param buildType 'Release' || 'Debug'
 * @param generator 'WindowsPhone' || 'WindowsStore'
 * @param args 
 */
function runCMake(sourceDir, buildDir, buildType, platform, arch, callback) {
	var prc,
		generator = 'Visual Studio 12 2013';
	
	// If the buildDir already exists, wipe it
	if (fs.existsSync(buildDir)) {
		wrench.rmdirSyncRecursive(buildDir);
	}
	wrench.mkdirSync(buildDir);

	if ('ARM' == arch) {
		generator += ' ARM';
	}

	prc = spawn('cmake', [
			'-G', generator,
			'-DCMAKE_SYSTEM_NAME=' + platform,
			'-DCMAKE_BUILD_TYPE=' + buildType,
			'-DCMAKE_SYSTEM_VERSION=8.1', 
			'-Wno-dev'
		],
		{
			cwd: buildDir
	});
	prc.stdout.on('data', function (data) {
	   console.log(data.toString().trim());
	});

	prc.on('close', function (code) {
		if (code != 0) {
			callback("Failed to run CMake");
		} else {
			callback();
		}
	});
}

function runMSBuild(slnFile, buildType, arch, callback) {
	var prc,
		args = ['/p:Configuration=' + buildType];
		if ('ARM' == arch) {
			args.unshift('/p:Platform=ARM');
		}
		args.unshift(slnFile);
	prc = spawn('MSBuild', args);
	prc.stdout.on('data', function (data) {
	   console.log(data.toString().trim());
	});

	prc.on('close', function (code) {
		if (code != 0) {
			callback("Failed to run MSBuild");
		} else {
			callback();
		}
	});
}

async.series([
	function (next) {
		console.log("Building Windows Phone 8.1 x86");
		runCMake('Source/Titanium', 'build/phone/x86', 'Release', 'WindowsPhone', 'x86', next);
	},
	function (next) {
		runMSBuild('build/phone/x86/TitaniumWindows.sln', 'Release', 'x86', next);
	},
	function (next) {
		console.log("Building Windows Phone 8.1 ARM");
		runCMake('Source/Titanium', 'build/phone/ARM', 'Release', 'WindowsPhone', 'ARM', next);
	},
	function (next) {
		runMSBuild('build/phone/ARM/TitaniumWindows.sln', 'Release', 'ARM', next);
	},
	function (next) {
		console.log("Building Windows Store x86");
		runCMake('Source/Titanium', 'build/store/x86', 'Release', 'WindowsStore', 'x86', next);
	},
	function (next) {
		runMSBuild('build/store/x86/TitaniumWindows.sln', 'Release', 'x86', next);
	},
	// TODO Do what package.bat does, copying files to a final distribution

], function (err, results) {
	if (err) {
		console.error(err.toString().red);
		process.exit(1);
	} else {
		process.exit(0);
	}
});

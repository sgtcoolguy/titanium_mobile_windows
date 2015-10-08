/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
var fs = require('fs'),
	colors = require('colors'),
	path = require('path'),
	home = process.env.HOME || process.env.USERPROFILE || process.env.APPDATA,
	spawn = require('child_process').spawn,
	os = require('os'),
	program = require('commander'),
	wrench = require('wrench'),
	symbols = {
	  ok: '✓',
	  err: '✖',
	  dot: '․'
	};

// With node.js on Windows: use symbols available in terminal default fonts
if ('win32' == os.platform()) {
	symbols.ok = '\u221A';
	symbols.err = '\u00D7';
	symbols.dot = '.';
}

////////////////////////////////////
////////// MAIN EXECUTION //////////
////////////////////////////////////

// Process command line input
program
	.description('Titanium Windows VS Solution Generator')
	.usage('COMMAND [ARGS] [OPTIONS]')
	.option('-a, --arch <arch>', '"ARM" (device) or "Win32" (emulator)')
	.option('-o, --outputPath <outputPath>', 'Output path for generated code')
	.option('-p, --platform <platform>', '"WindowsPhone" or "WindowsStore"')
	.option('-t, --target <platform target>', '"8.1" or "10.0"')
	.option('-m, --msdev <msbuild version>', '"12" (VS 2013) or "14" (VS 2015)');

program.command('new'.blue+' <example_name>'.white)
		.description('    create a new project from the packaged examples'.grey);

program.parse(process.argv);

Error.stackTraceLimit = Infinity;

if (program.args.length === 0)
{
	var help = program.helpInformation();
	help = help.replace('Usage: generate_project COMMAND [ARGS] [OPTIONS]','Usage: '+'generate_project'.blue+' COMMAND'.white+' [ARGS] [OPTIONS]'.grey);
	//help = logger.stripColors ? colors.stripColors(help) : help;
	console.log(help);
	process.exit(0);
}

// Validate the platform
if (program.platform && program.platform != 'WindowsPhone' && program.platform != 'WindowsStore') {
	console.log('Invalid platform "' + program.platform + '" specified, must be one of ["WindowsPhone", "WindowsStore"]');
	process.exit(1);
}

// validate the arch
if (program.arch && program.arch != 'Win32' && program.arch != 'ARM') {
	console.log('Invalid arch "' + program.arch + '" specified, must be one of ["Win32", "ARM"]');
	process.exit(1);
}

// Validate the given command, only can be 'new' right now
var command = program.args[0];
if (command != 'new') {
	console.log('Unknown command: ' + command.red);
	process.exit(1);
}
var example_name = program.args[1] || 'NG';
var platform = program.platform || 'WindowsPhone';
var arch = program.arch || 'Win32';
var dest = program.outputPath || path.join('.', example_name + '.' + platform + '.' + arch);
// Make sure our intended output dir exists!
if (!fs.existsSync(dest)) {
	// Make the directory structure!
	wrench.mkdirSyncRecursive(dest);
}
var generator = program.msdev == '14' ? 'Visual Studio 14 2015' : 'Visual Studio 12 2013';
var generator_target = program.target || '8.1';

if (arch == 'ARM') {
	generator += ' ARM';
}

var example_folder = path.join(__dirname, '..', '..', 'Examples', example_name);
// Now let's generate the solution
var prc = spawn('cmake', ['-G', generator,
	'-DCMAKE_SYSTEM_NAME=' + platform, 
	'-DCMAKE_SYSTEM_VERSION=' + generator_target,
    '-DTitaniumWindows_DISABLE_TESTS=ON',
    '-DTitaniumWindows_Global_DISABLE_TESTS=ON',
    '-DTitaniumWindows_Ti_DISABLE_TESTS=ON',
    '-DTitaniumWindows_UI_DISABLE_TESTS=ON',
    '-DTitaniumKit_DISABLE_TESTS=ON',
    '-DHAL_DISABLE_TESTS=ON',
    example_folder
	], {
		cwd: dest
	});
prc.stdout.on('data', function (data) {
   console.log(data.toString());
});
prc.stderr.on('data', function (data) {
   console.log(data.toString());
});
prc.on('close', function (code) {
	var setProcess;
	if (code != 0) {
		console.log("Failed to generate project!");
		process.exit(1);
	} else {
		console.log((symbols.ok + ' Generated VS solution. Open ' + dest + '\\' + example_name + '.sln to begin development.').green);
		process.exit(0);
	}
});

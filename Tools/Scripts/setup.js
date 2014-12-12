
/**
 * Displays installed Titanium SDKs and installs new SDKs.
 *
 * @module commands/sdk
 *
 * @see SdkSubcommands
 *
 * @copyright
 * Copyright (c) 2009-2013 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * @requires node-appc
 */
 var async = require('async'),
	fs = require('fs'),
	http = require('http'),
	path = require('path'),
	request = require('request'),
	temp = require('temp'),
	wrench = require('wrench'),
	appc = require('node-appc'),
	home = process.env.HOME,
	spawn = require('child_process').spawn,
	os = require('os');

function downloadURL(url, callback) {
	console.log('Downloading %s', url.cyan);

	var tempName = temp.path({ suffix: '.zip' }),
		tempDir = path.dirname(tempName);
	fs.existsSync(tempDir) || wrench.mkdirSyncRecursive(tempDir);

	var tempStream = fs.createWriteStream(tempName),
		req = request({ url: url });

	req.pipe(tempStream);

	req.on('error', function (err) {
		fs.existsSync(tempName) && fs.unlinkSync(tempName);
		console.log();
		console.error('Failed to download URL: %s', err.toString() + '\n');
		process.exit(1);
	});

	req.on('response', function (req) {
		if (req.statusCode >= 400) {
			// something went wrong, abort
			console.log();
			console.error('Request failed with HTTP status code %s %s\n', req.statusCode, http.STATUS_CODES[req.statusCode] || '');
			process.exit(1);
		} else if (req.headers['content-length']) {
			// we know how big the file is, display the progress bar
			var total = parseInt(req.headers['content-length']),
				bar;
			
			bar = new appc.progress('  :paddedPercent [:bar] :etas', {
				complete: '='.cyan,
				incomplete: '.'.grey,
				width: 40,
				total: total
			});

			req.on('data', function (buffer) {
				bar.tick(buffer.length);
			});
			

			tempStream.on('close', function () {
				if (bar) {
					bar.tick(total);
					console.log('\n');
				}
				callback(tempName);
			});
		} else {
			// we don't know how big the file is, display a spinner
			var busy;

			if (!cli.argv.quiet && !!cli.argv['progress-bars']) {
				busy = new appc.busyindicator;
				busy.start();
			}

			tempStream.on('close', function () {
				busy && busy.stop();
				logger.log();
				callback(tempName);
			});
		}
	});
}

function extract(filename, installLocation, keepFiles, callback) {
	console.log('Extracting to %s', installLocation.cyan);

	var bar;

	appc.zip.unzip(filename, installLocation, {
		visitor: function (entry, i, total) {
			if (i == 0) {
				bar = new appc.progress('  :paddedPercent [:bar]', {
					complete: '='.cyan,
					incomplete: '.'.grey,
					width: 40,
					total: total
				});
			}

			bar && bar.tick();
		}
	}, function (err, extracted, total) {
		if (err) {
			keepFiles || fs.unlinkSync(filename);
			console.log();
			console.error('Failed to unzip');
			String(err).trim().split('\n').forEach(console.error);
			console.log();
			process.exit(1);
		} else {
			if (bar) {
				bar.tick(total);
				console.log('\n');
			}
			keepFiles || fs.unlinkSync(filename);
			callback();
		}
	});
}

function setENV(key, value, next) {
	var prc;
	if (os.platform() === 'win32') {
		prc = spawn('SetX', [key, value]);
		prc.stdout.on('data', function (data) {
		    console.log(data.toString());
		});

		prc.on('close', function (code) {
		    next();
		});
	} else {
		// FIXME Batch together all the changes and modify the ~/.bash_profile for the user (after making a copy)?
		console.log('Please set the environment variable %s to %s', key, value);
		console.log('The easiest way to achieve this to to append the following to your ~/.bash_profile:\n\nexport %s=%s\n', key, value);
		next();
	}
}


async.series([
	// FIXME if the destinations already exist, we don't need to download!
    function (next) {
    	if (typeof process.env.GTEST_ROOT !== 'undefined') {
    		next();
    	}
		else {
			downloadURL("http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-windows.zip", function (filename) {
				// TODO How can I fire this off to start but then proceed to next DL in parallel?
				extract(filename, home, true, function () {
					var gtest_root = path.join(home, "gtest-1.7.0-windows");
					setENV('GTEST_ROOT', gtest_root, next);
				});
			});
		}
    },
    function (next) {
      	if (typeof process.env.SQLite_HOME !== 'undefined') {
    		next();
    	} else {
		    downloadURL("http://timobile.appcelerator.com.s3.amazonaws.com/SQLite-Windows-1415143965334.zip", function (filename) {
				// mkdir "SQLite-Windows-1415143965334" and unzip to _that_!
				var sqliteDir = path.join(home, "SQLite-Windows-1415143965334");
				fs.existsSync(sqliteDir) || wrench.mkdirSyncRecursive(sqliteDir);
				extract(filename, sqliteDir, true, function () {
					setENV('SQLite_HOME', sqliteDir, next);
				});
			});
		}
    },
    function (next) {
    	if (typeof process.env.BOOST_ROOT !== 'undefined') {
    		next();
    	} else {
		    downloadURL("http://hivelocity.dl.sourceforge.net/project/boost/boost/1.57.0/boost_1_57_0.zip", function (filename) {
				var boostRoot = path.join(home, "boost_1_57_0");
				// FIXME Extracting this takes a loooong time. Can we tell it to go ahead and do the extraction and the next download
				// in parallel?
				
				// This is actually soooo slow on my VM that it'd probably be faster to download 7zip, and download this in 7z and extract using that!
				extract(filename, home, true, function () {
					setENV('BOOST_ROOT', boostRoot, next);
				});
			});
		}
    },
    function (next) {
    	if (typeof process.env.JavaScriptCore_HOME !== 'undefined') {
    		next();
    	} else {
		    downloadURL("http://timobile.appcelerator.com.s3.amazonaws.com/jscore/JavaScriptCore-Windows-1411436814.zip", function (filename) {
				extract(filename, home, true, function() {
					var sqliteDir = path.join(home, "JavaScriptCore-Windows-1411436814");
					setENV('JavaScriptCore_HOME', sqliteDir, next);
				});
			});
		}
    },
    // Add the included cmake bin dir to the user's PATH?
    function (next) {
    	// TODO If we can find cmake.exe on PATH, don't do this?
	    var cmakeBinPath = path.join(__dirname, '..', '..', 'cli', 'vendor', 'cmake', 'bin');
	    if (process.env.PATH.indexOf(cmakeBinPath) == -1) {
			console.log("Appending %s to PATH", cmakeBinPath);
	    	setENV('PATH', process.env.PATH + ';' + cmakeBinPath, next);
		} else {
			next();
		}
    },
    // Change Windows PowerShell permissions
    function (next) {
    	if (os.platform() === 'win32') {
    		// TODO Don't change the policy if it's already what we want!
    		console.log("Changing PowerShell policy to RemoteSigned for CLI");
			var prc = spawn(process.env.SystemRoot + '\\system32\\WindowsPowerShell\\v1.0\\powershell.exe', ['Set-ExecutionPolicy', '-ExecutionPolicy', 'RemoteSigned', '-Scope', 'CurrentUser']);
			prc.stdout.on('data', function (data) {
			    console.log(data.toString());
			});

			prc.on('close', function (code) {
				if (code != 0) {
					next("Failed to change PowerShell policy");
				} else {
			    	next();
				}
			});
		} else {
			next();
		}
    }
    // TODO Download VS2013 Express? (It's Huuuuuuge! 6.61 GB!)
], function (err, results) {
	if (err) {
		console.error(err.toString());
		process.exit(1);
	}
});

/**
 * Signs an app and copies the result to the specified output directory.
 *
 * @copyright
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

const
	appc = require('node-appc'),
	fs = require('fs'),
	path = require('path'),
	wrench = require('wrench'),
	moment = require('moment'),
	async = require('async'),
	windowslib = require('windowslib'),
	__ = appc.i18n(__dirname).__;

exports.cliVersion = '>=3.2';

exports.init = function (logger, config, cli) {

	cli.on('build.pre.compile', {
		priority: 10000,
		post: function (builder, finished) {
			if (builder.buildOnly || !/^ws-local|dist-winstore$/.test(builder.target)) {
				return finished();
			}

			var projectDir = builder.projectDir,
				wSDK = builder.windowsInfo.windows[builder.wpsdk],
				wsCert = builder.wsCert;

			if (wsCert) {
				builder.certificatePath = wsCert;
				windowslib.certs.thumbprint(wsCert, builder.pfxPassword, function (err, thumbprint) {
					builder.certificateThumbprint = thumbprint;
					finished();
				});

				return;
			}

			var expirationDate = moment().add(1, 'year').format('MM/DD/YYYY'),
				pvk = path.join(projectDir, 'generated.pvk'),
				cer = path.join(projectDir, 'generated.cer'),
				pfx = path.join(projectDir, 'generated.pfx');

			async.series([
				function checkCertificates(next) {
					if (fs.existsSync(pvk) && fs.existsSync(cer)) {
						logger.info(__('Using existing generated pvk and cer'));
						return next();
					}

					logger.info('');
					logger.info(__('Creating a certificate'));
					logger.info(__('Please follow the prompts'));
					windowslib.certs.generate(builder.publisherName, cer, builder.windowslibOptions, function(err, privateKey, certFile) {
						return !err ? next() : next(err || new Error('Certificate generation failed'));
					});
				},
				function checkPFX(next) {
					if (fs.existsSync(pfx)) {
						logger.info(__('Using existing generated pfx'));
						return next();
					}
					logger.info(__('Creating a PFX'));
					windowslib.certs.generatePFX(pvk, cer, pfx, builder.pfxPassword, builder.windowslibOptions, function(err, pfxFile) {
						if (err) {
							next(err);
						}
						else if (!fs.existsSync(pfx)) {
							next(new Error('PFX file was not generated at: "' + pfx + '"'));
						}
						else {
							next();
						}
					});
				},
				function makeSurePFXIsInstalled(next) {
					// No password?
					if (!builder.pfxPassword) {
						// Visual Studio can import the pfx on its own without us. Move on!
						return next();
					}
					// Otherwise...
					logger.info('');
					logger.info(__('Importing PFX'));
					logger.info(__('Please follow the prompts'));
					logger.info(__('(The default options will suffice)'));
					require('child_process').exec('start ' + pfx, function (err) {
						// Give them a bit of time to finish the import process.
						setTimeout(next, 5000);
					});
				},
				function usePFX(next) {
					builder.certificatePath = pfx;
					windowslib.certs.thumbprint(pfx, builder.pfxPassword, function (err, thumbprint) {
						builder.certificateThumbprint = thumbprint;
						err ? next(err) : next();
					});
				}
			], finished);
		}
	});

	cli.on('build.post.compile', {
		priority: 10000,
		post: function (builder, finished) {
			if (builder.buildOnly || builder.target !== 'dist-winstore') {
				return finished();
			}

			var outputDir = builder.outputDir,
				wpARMDir = builder.cmakeTargetDir,
				releaseDir = path.join(wpARMDir, 'Release'),
				bundle = path.join(releaseDir, fs.readdirSync(releaseDir).filter(function (f) {
					return f.indexOf('_Bundle') >= 0;
				})[0]),
				appx = path.join(bundle, fs.readdirSync(bundle).filter(function (f) {
					return f.indexOf('.appx') >= 0 && f.indexOf('_scale') === -1;
				})[0]),
				dest = path.join(outputDir, path.basename(appx));

			if (outputDir && outputDir != path.dirname(appx)) {
				fs.existsSync(outputDir) || wrench.mkdirSyncRecursive(outputDir);
				fs.existsSync(dest) && fs.unlinkSync(dest);
				appc.fs.copyFileSync(appx, dest, {logger: logger.debug});
			}

			logger.info(__('Packaging complete'));
			logger.info(__('Package location: %s', dest.cyan));
			finished();
		}
	});
};

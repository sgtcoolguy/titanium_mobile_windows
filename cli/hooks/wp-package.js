/**
 * Signs an app and copies the result to the specified output directory.
 *
 * @copyright
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
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
	__ = appc.i18n(__dirname).__;

exports.cliVersion = '>=3.2';

exports.init = function (logger, config, cli) {

	cli.on('build.post.compile', {
		priority: 10000,
		post: function (builder, finished) {
			if (builder.buildOnly || builder.target !== 'dist-phonestore') return finished();

			/*
			TODO: sign the app. all you need to do is:

			logger.info(__('Signing app'));

			appc.subprocess.run(builder.windowsInfo.windowsphone[builder.wpsdk].xapSignTool, [
			], function () {
				var signedApp = path.join(builder.buildTargetProductDir, 'someapp.xap'),
					outputDir = builder.outputDir;

				if (outputDir && outputDir != path.dirname(signedApp)) {
					fs.existsSync(outputDir) || wrench.mkdirSyncRecursive(outputDir);
					dest = path.join(outputDir, path.basename(dest));
					fs.existsSync(dest) && fs.unlinkSync(dest);
					appc.fs.copyFileSync(builder.apkFile, dest, { logger: logger.debug });
				}

				logger.info(__('Packaging complete'));
				logger.info(__('Package location: %s', dest.cyan));

				finished();
			});
			*/

			finished(); // temp
		}
	});

};

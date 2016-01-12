/**
 * Windows clean command.
 *
 * @module cli/_clean
 *
 * @copyright
 * Copyright (c) 2016 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var path = require('path');

exports.scanHooks = function(logger, config, cli) {
	cli.scanHooks(path.join(__dirname, '..', 'hooks'));
}

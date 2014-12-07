/*
 * something cool module
 */

exports.saySomething = function(_somethingCool) {
	Ti.API.info('Something cool from foo is ' + _somethingCool);	
};

Ti.API.info('foo module loaded');
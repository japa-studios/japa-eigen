/*
 * japa-eigen
 * https://github.com/japa-studios/japa-eigen
 *
 * Copyright (c) 2014 Guilherme Ando de Toledo
 * Licensed under the MIT license.
 */

'use strict';

exports.awesome = function() {
  return 'awesome';
};

exports.gyp = function(num) {
	var addon = require('../build/Release/addon');
	var obj = new addon.MyObject(num);
	return obj.plusOne();
};

exports.matrix = function(num) {
	var addon = require('../build/Release/addon');
	var obj = new addon.MyObject(num);
	return obj.matrix();
};

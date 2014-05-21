'use strict';

var japaEigen = require('../lib/japa-eigen.js');

/*
  ======== A Handy Little Nodeunit Reference ========
  https://github.com/caolan/nodeunit

  Test methods:
    test.expect(numAssertions)
    test.done()
  Test assertions:
    test.ok(value, [message])
    test.equal(actual, expected, [message])
    test.notEqual(actual, expected, [message])
    test.deepEqual(actual, expected, [message])
    test.notDeepEqual(actual, expected, [message])
    test.strictEqual(actual, expected, [message])
    test.notStrictEqual(actual, expected, [message])
    test.throws(block, [error], [message])
    test.doesNotThrow(block, [error], [message])
    test.ifError(value)
*/

exports.japaEigen = {
  setUp: function(done) {
    // setup here
    done();
  },
  'no args': function(test) {
    test.expect(1);
    // tests here
    test.equal(japaEigen.awesome(), 'awesome', 'should be awesome.');
    test.done();
  },
  'matrix': function(test) {
    test.expect(1);
    // tests here
    test.equal(japaEigen.matrix(10), 11, 'should be 11.');
    test.done();
  },
  'gyp': function(test) {
    test.expect(1);
    // tests here
    test.equal(japaEigen.gyp(10), 11, 'should be 11.');
    test.done();
  }
};

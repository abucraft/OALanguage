var tree = require('./tree-graph');
var compilerNative = require('../build/Release/parser');
var fs = require('fs');
var tokenPath = "../tokenStream";
exports.visualize = function (filename) {
	if(filename == null||typeof filename != 'string'){
		alert('文件名为空');
		return;
	}
	alert('文件名为空');
		return;
	compilerNative.getTree(filename, function (err, textJson) {
		if (err != null) {
			alert(err);
			return;
		}
		tree.drawTree(textJson);
		try {
			fs.readFile(tokenPath, 'utf-8', function (err, content) {
				if (err != null) {
					alert(err);
				}
				tree.showToken(content);
			});
		} catch (err) {
			alert(err);
		}
	});

}
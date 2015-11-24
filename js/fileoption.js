var fs = require('fs');

function getContent(fpath,callback){
	fs.readFile(fpath,'utf8',function(err,data){
		if(err!=null){
			callback(err,null);
			return;
		}else{
			callback(null,data);
		}
	});
}

exports.getContent = getContent;
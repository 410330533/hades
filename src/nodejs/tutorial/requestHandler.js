// npm install formidable
// var exec = require('child_process').exec;
var querystring = require('querystring'),
    fs = require('fs'),
    formidable = require('formidable');

function start(response, request){
    var body = '<html>'+
    '<head>'+
    '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />'+
    '</head>'+
    '<body>'+
    '<form action="/upload" enctype="multipart/form-data" method="post">'+
    '<input type="file" name="upload" />'+
    '<input type="submit" value="Submit text" />'+
    '</form>'+
    '</body>'+
    '</html>';
    
    response.writeHead(200, {'Content-type': 'text/html'});
    response.write(body);
    response.end();
};

function upload(response, request){
    var form = new formidable.IncomingForm();
    form.parse(request, function (error, fields, files){
        fs.renameSync(files.upload.path, '/tmp/test.jpg');
        response.writeHead(200, {'Content-type': 'text/html'});
        response.write("received image: <br/>");
        response.write('<img src="/show" />');
        response.end();
    });
    
    // response.writeHead(200, {'Content-type': 'text/plain'});
    // response.write('you have sent: ' + querystring.parse(postData).text);
    // response.end();
};

function show(response, request){
    fs.readFile('/tmp/test.jpg', 'binary', function (error, file){
        if (error){
            response.writeHead(500, {'Content-type': 'text/plain'});
            response.write(error + "\n");
            response.end();
        } else {
            response.writeHead(200, {'Content-type': 'image/jpg'});
            response.write(file, 'binary');
            response.end();
        }
    });
};

exports.start = start;
exports.upload = upload;
exports.show = show;
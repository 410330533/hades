var http = require('http');
var url = require('url');

function start(route, handle){
    function onRequest(request, response){
        // var postData = '';
        var pathname = url.parse(request.url).pathname;
        
        // request.setEncoding('utf8');
        
        // request.addListener('data', function (postDataChunk){
            // postData += postDataChunk;
            // console.log("Received POST data chunk '" + postDataChunk + "'.");
        // });
        // request.addListener('end', function (){
            // route(handle, pathname, response, postData);
        // });
        route(handle, pathname, response, request);
    }
    
    http.createServer(onRequest).listen(8888);
    console.log('Server started at http://127.0.0.1:8888');
};

exports.start = start;
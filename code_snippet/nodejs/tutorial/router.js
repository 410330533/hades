function route(handle, pathname, response, request){
    if (pathname == '/favicon.ico'){
        return '';
    }
    
    if (typeof handle[pathname] === 'function'){
        handle[pathname](response, request);
    } else {
        console.log('no request handler found for ' + pathname);
        response.writeHead(404, {'Content-type':'text/plain'});
        response.write('404 not found');
        response.end();
    }
};

exports.route = route;
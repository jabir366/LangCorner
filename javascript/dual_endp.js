const http2 = require('http2');
const fs = require('fs');

const options = {
      // key: fs.readFileSync('server.key'),
      // cert: fs.readFileSync('server.crt')
};

// const server = http2.createSecureServer(options, (req, res) => {
const server = http2.createServer(options, (req, res) => {
      // Handle HTTP/1.1 requests here
       res.writeHead(200);
         res.end('Hello HTTP/1.1\n');
       });
    
       server.on('stream', (stream, headers) => {
          // Handle HTTP/2 requests here
          stream.respond({
           'content-type': 'text/plain',
           ':status': 200
            });
          stream.end('Hello HTTP/2\n');
       });
    
       server.listen(3000, () => {
          console.log('Server listening on port 3000');
        });

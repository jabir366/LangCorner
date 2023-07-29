const http2 = require('http2');
const fs = require('fs');

const options = {
  // key: fs.readFileSync('server.key'),
  // cert: fs.readFileSync('server.crt')
};

const handleHTTP11Request = (req, res) => {
  console.log("http req");
  res.writeHead(200);
  res.end('Hello HTTP/1.1\n');
};

const handleHTTP2Request = (stream, headers) => {
  console.log("http2 req");
  stream.respond({
    'content-type': 'text/plain',
    ':status': 200
  });
  stream.end('Hello HTTP/2\n');
};

//const server = http2.createSecureServer(options);
const server = http2.createServer(options);

server.on('request', handleHTTP11Request);
server.on('stream', handleHTTP2Request);
server.on('connection', (socket) => {
  console.log('New connection', socket.remoteAddress);
});
server.on('error', (err) => {
  console.error('Server error', err);
});

server.listen(3000, () => {
  console.log('Server listening on port 3000');
});

const http2 = require('http2');
const fs = require('fs');

const options = {
  //key: fs.readFileSync('server.key'),
  //cert: fs.readFileSync('server.crt')
};
//const server = http2.createSecureServer(options);
const server = http2.createServer(options);

const handleHTTP2Request = (stream, headers) => {
  console.log(headers)
  if (headers[':method'] === 'POST' ) {
    let data = '';
    stream.on('data', (chunk) => {
      data += chunk.toString();
    });
    stream.on('end', () => {
      let parsedData = JSON.parse(data);
      stream.respond({
        'content-type': 'application/json',
        ':status': 200
      });
      stream.end(JSON.stringify({ message: 'Data received successfully' }));
    });
  } else {
    stream.respond({
      'content-type': 'text/plain',
      ':status': 400
    });
    stream.end('Bad Request');
  }
}

server.on('stream', handleHTTP2Request);

server.listen(3000, () => {
  console.log('Server listening on port 3000');
});


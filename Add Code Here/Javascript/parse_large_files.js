const fs = require('fs');

const filePath = './data.txt';
const readStream = fs.createReadStream(filePath, { encoding: 'utf8' });

var writeRes = fs.createWriteStream('./output.txt', {encoding: "utf8"});

readStream.on('data', (chunks) => {
    const lines = chunks.split('\n');
    for (let i = 0; i < lines.length; i++) {
        if (lines[i].includes("Ok")) {
            writeRes.write(lines)
        }
    }
});

readStream.on('end', () => {
  writeRes.end()
});

readStream.on('error', (err) => {
    console.log(err)
});

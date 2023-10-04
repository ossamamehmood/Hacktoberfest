const express = require('express');
const bodyParser = require('body-parser');
const shortid = require('shortid');

const app = express();
const port = 3000;

// Create a mapping to store the shortened URLs
const urlDatabase = {};

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('public'));

// Render the homepage
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

// Redirect short URL to the original URL
app.get('/:shortCode', (req, res) => {
  const shortCode = req.params.shortCode;
  const longUrl = urlDatabase[shortCode];
  if (longUrl) {
    res.redirect(longUrl);
  } else {
    res.status(404).send('Short URL not found');
  }
});

// Handle URL shortening form submission
app.post('/shorten', (req, res) => {
  const longUrl = req.body.longUrl;
  const shortCode = shortid.generate();

  // Store the mapping of short code to the long URL
  urlDatabase[shortCode] = longUrl;

  // Return the shortened URL
  const shortUrl = `${req.protocol}://${req.get('host')}/${shortCode}`;
  res.send(`Shortened URL: <a href="${shortUrl}">${shortUrl}</a>`);
});

app.listen(port, () => {
  console.log(`URL shortener app listening at http://localhost:${port}`);
});

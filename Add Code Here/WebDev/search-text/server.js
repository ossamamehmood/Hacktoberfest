const express = require('express');
const path = require('path');

const port = 2222;
const app = express();

app.use('/', express.static(path.join(__dirname, 'public')));

app.get('/search', (req, res) => {
  console.log(req.query.q);
});

app.listen(port, () => {
  console.log(`app running on http://localhost:${port}`);
});

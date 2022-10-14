var path = require('path');
var express = require('express');
var expressLayouts = require('..');

var app = express();

app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
app.set('layout extractScripts', true)
app.set('layout extractStyles', true)

app.use(expressLayouts);

app.get('/', function(req, res) {
  res.locals = {
    title: 'Example',
    message: 'This is a message'
  };
  res.render('view', {
    // additional locals, a custom layout, or other options can be defined here
  });
});

var port = 3000;
app.listen(port, function() {
  console.log('Listening on http://localhost:%s/', port);
});

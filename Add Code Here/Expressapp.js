const express = require('express');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
const session = require('express-session');

const app = express();

// Configure session middleware
app.use(session({ secret: 'your-secret-key', resave: true, saveUninitialized: true }));

// Initialize Passport and session support
app.use(passport.initialize());
app.use(passport.session());

// Define a sample user
const sampleUser = {
  id: 1,
  username: 'user',
  password: 'password',
};

// Use the local strategy for authentication
passport.use(new LocalStrategy((username, password, done) => {
  if (username === sampleUser.username && password === sampleUser.password) {
    return done(null, sampleUser);
  } else {
    return done(null, false, { message: 'Incorrect username or password' });
  }
}));

// Serialize and deserialize user
passport.serializeUser((user, done) => {
  done(null, user.id);
});

passport.deserializeUser((id, done) => {
  if (id === sampleUser.id) {
    done(null, sampleUser);
  } else {
    done(null, false);
  }
});

// Routes
app.get('/', (req, res) => {
  res.send('Welcome to the home page.');
});

app.get('/login', (req, res) => {
  res.send('Login page');
});

// Implement your login and authentication routes here

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});

const express = require('express');
const { check } = require('express-validator');
const authController = require('../controllers/authController');

const router = express.Router();

// Register a new user
router.post(
  '/register',
  [
    check('username', 'Please enter a valid username').notEmpty(),
    check('password', 'Please enter a password with 6 or more characters').isLength({ min: 6 }),
  ],
  authController.registerUser
);

// Login user
router.post('/login', authController.loginUser);

module.exports = router;

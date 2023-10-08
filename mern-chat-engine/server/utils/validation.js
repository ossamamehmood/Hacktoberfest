const { check } = require('express-validator');

const validateRegistration = [
  check('username', 'Please enter a valid username').notEmpty(),
  check('password', 'Please enter a password with 6 or more characters').isLength({ min: 6 }),
];

const validateLogin = [
  check('username', 'Please enter a valid username').notEmpty(),
  check('password', 'Please enter a password with 6 or more characters').isLength({ min: 6 }),
];

module.exports = {
  validateRegistration,
  validateLogin,
};

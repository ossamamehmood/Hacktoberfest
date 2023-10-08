const express = require('express');
const authMiddleware = require('../middleware/authMiddleware');
const userController = require('../controllers/userController');

const router = express.Router();

// Get user profile
router.get('/profile', authMiddleware, userController.getUserProfile);

// Update user profile
router.put('/profile', authMiddleware, userController.updateUserProfile);

module.exports = router;

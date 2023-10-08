const express = require('express');
const authMiddleware = require('../middleware/authMiddleware');
const roomController = require('../controllers/roomController');

const router = express.Router();

// Create a new chat room
router.post('/create', authMiddleware, roomController.createRoom);

// Join a chat room
router.post('/join/:id', authMiddleware, roomController.joinRoom);

// Leave a chat room
router.post('/leave/:id', authMiddleware, roomController.leaveRoom);

// Get all chat rooms
router.get('/', authMiddleware, roomController.getAllRooms);

// Get chat room by ID
router.get('/:id', authMiddleware, roomController.getRoomById);

module.exports = router;

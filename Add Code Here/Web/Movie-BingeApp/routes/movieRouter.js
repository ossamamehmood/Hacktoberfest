const express = require('express')
const movieCollector = require('../collector/movieCollector')
const router = express.Router()

router
.route('/')
.get(movieCollector.getAllMovies)

router
.route('/movie/:slug')
.get(movieCollector.getMovie);


module.exports = router


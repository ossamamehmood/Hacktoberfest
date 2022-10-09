const express = require('express')
const path = require('path')
const movieRouter = require('./routes/movieRouter')


const app = express()

app.use(express.static(path.join(__dirname, './public')))
app.set('view engine','pug')
app.set('views', path.join(__dirname, './views'))

app.use('/', movieRouter)


module.exports = app

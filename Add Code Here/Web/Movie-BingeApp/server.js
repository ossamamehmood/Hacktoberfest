const app = require('./app')
const dotenv = require('dotenv')
const mongoose = require('mongoose')

dotenv.config({path: './config.env'})

const DB = process.env.DB.replace('<PASSWORD>',process.env.DB_PASSWORD)
const port = process.env.PORT || 3000;

mongoose.connect(DB).then(()=>{
    console.log('DATABASE CONNECTION SUCCESSFUL')
})


app.listen(port, ()=>{
    console.log(`Server is listening at PORT: ${port}`)
})
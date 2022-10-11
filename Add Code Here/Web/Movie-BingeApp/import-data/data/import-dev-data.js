const mongoose = require('mongoose')
const fs = require('fs')
const movieModels = require('./../../models/movieModel')
const dotenv = require('dotenv')

dotenv.config({path: './config.env'})

const data = JSON.parse(fs.readFileSync('./import-data/data/data.json'))
const DB = process.env.DB.replace('<PASSWORD>',process.env.DB_PASSWORD)

mongoose.connect(DB)
.then(()=>{
    // console.log('Database Connection is successful')
}).catch((err)=>{
    console.log(err)
})

async function importData(){
    
    data.forEach(async(element)=>{
        try{
            const movie = await movieModels.create(element)
            while(movie.cast.length>0){
                movie.cast.pop()
            }
            console.log(movie)
            element.cast.forEach(ele=>{
                movie.cast.push(ele)
            })
            await movie.save()
        }catch(err){
            console.log(err)
        }
    })
}

async function deleteData(){
    try{
        await movieModels.deleteMany()
    }catch(err){
        console.log(err)
    }
}

if(process.argv[2]==='--import'){
    importData()
}
else if(process.argv[2]==='--delete'){
    deleteData()
}
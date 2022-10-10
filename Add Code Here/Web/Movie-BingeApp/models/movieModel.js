const mongoose = require('mongoose')

const castSchema = new mongoose.Schema({
    name: String,
    image: String
})
const movieSchema = new mongoose.Schema({
    title: {
        type: String,
        required: [true, 'title is required'],
    },
    genre: [{type: String,}],
    runtime: {
        type: String,
    },
    ratings: {
        type:String
    },
    "release date": {
        type: String,
    },
    Description: {
        type: String
    },
    watch: {
        type: String
    },
    directors: {
        type: String
    },
    Writers: {
        type: String
    },
    cast: [castSchema],
    poster: String,
    posterList: [
        {
            type: String
        }
    ],
    slug: {
        type: String
    }

})


const movieModel = mongoose.model('movie', movieSchema)

module.exports = movieModel
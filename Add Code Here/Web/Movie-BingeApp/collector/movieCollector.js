const { render } = require('pug')
const movieModels = require('./../models/movieModel')


exports.getAllMovies = async function(req,res){
    try{
        const movies = await movieModels.find()
        res
        .status(200)
        .render('home',{
            title: 'MovieBinge | Binge watch movies',
            movies: movies
        })
    }catch(err){
        res
        .status(404)
        .json({
            status: 'failure',
            message: err
        })
    }
}

exports.getMovie = async function(req,res){
    try{
        console.log(req.url)
        const movie = await movieModels.findOne({
            slug: req.params.slug
        })
        res
        .status(200)
        .render('movie',{
            title: `MovieBinge | ${req.params.slug}`,
            movie: movie
        })
    }catch(err){
        res
        .status(404)
        .json({
            status: 'failure',
            message: err
        })
    }
}
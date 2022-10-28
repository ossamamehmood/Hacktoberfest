import {id} from './index.js'

function loadPokemonDetails(id) {
  pokeAPI.getPokemon(id).then((pokemon) => {
    console.log(pokemon)
  })
}

document.body.onLoad = loadPokemonDetails(id)
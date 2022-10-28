export const pokeAPI = {}

pokeAPI.getPokemons = (offset=0, limit=10) => {
  const url = `https://pokeapi.co/api/v2/pokemon?offset=${offset}&limit=${limit}`

  return fetch(url)
    .then(res => res.json())
    .then(pokemons => pokemons.results)
    .catch(err => console.error(err))
    .then(results => results.map(pokeAPI.getPokemonsDetails))
    .then(detailsRequests => Promise.all(detailsRequests))
    .then((pokemonDetails) => {
      return pokemonDetails 
    })
}

pokeAPI.getPokemonsDetails = (pokemon) => {
  return fetch(pokemon.url)
    .then(res => res.json())
    .then(details => details)
    .catch(err => console.error(err))
}

pokeAPI.getPokemon = (pokemon) => {
  const url = `https://pokeapi.co/api/v2/pokemon/${pokemon}`

  return fetch(url)
    .then(res => res.json())
    .then(details => details)
    .catch(err => console.error(err))
}
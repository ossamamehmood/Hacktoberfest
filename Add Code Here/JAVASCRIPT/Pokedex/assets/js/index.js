import { pokeAPI } from './api.js'

let offset = 0
let id
const pokemonList = document.querySelector('[data-js="pokemon-list"]')
const next = document.querySelector('[data-js="next"]')
const prev = document.querySelector('[data-js="prev"]')
let detailsModal = document.querySelector('[data-js="details-modal"]')
const closeModal = document.querySelector('[data-js="close-modal"]')
const modalContent = document.querySelector('[data-js="modal-content"]')
let hpPercentage = 0
let attackPercentage = 0
let defensePercentage = 0
let specialAttackPercentage = 0
let specialDefensePercentage = 0
let speedPercentage = 0

if(document.title == 'Pokedex | Início') {
  const inputSearch = document.querySelector('[data-js="search-pokemon"]')
  const btnSearch = document.querySelector('[data-js="btn-search"]')

  btnSearch.addEventListener('click', (e) => {
    e.preventDefault()
    const pokemonName = inputSearch.value.toLowerCase()
    pokeAPI.getPokemon(pokemonName).then((pokemon) => {
      createPokemonDetails(pokemon)
    })
    detailsModal.classList.remove('hidden')
  })
  
}

function removeDetails() {
  detailsModal.classList.add('hidden')
  const hpBar = modalContent.querySelector('[data-js="hp-bar"]')
  hpBar.classList.remove(`w-[${hpPercentage}%]`)
  const attackBarPercentage = modalContent.querySelector('[data-js="attack-percentage"]')
  attackBarPercentage.classList.remove(`w-[${attackPercentage}%]`)
  const defenseBarPercentage = modalContent.querySelector('[data-js="defense-percentage"]')
  defenseBarPercentage.classList.remove(`w-[${defensePercentage}%]`)
  const specialAttackBarPercentage = modalContent.querySelector('[data-js="special-attack-percentage"]')
  specialAttackBarPercentage.classList.remove(`w-[${specialAttackPercentage}%]`)
  const specialDefenseBarPercentage = modalContent.querySelector('[data-js="special-defense-percentage"]')
  specialDefenseBarPercentage.classList.remove(`w-[${specialDefensePercentage}%]`)
  const speedBarPercentage = modalContent.querySelector('[data-js="speed-percentage"]')
  speedBarPercentage.classList.remove(`w-[${speedPercentage}%]`)
}

window.onclick = function(event) {
  if (event.target == detailsModal) {
    removeDetails()
  }
}

closeModal.addEventListener('click', () => {
  removeDetails()
})

if(document.title == 'Pokedex') {

  next.addEventListener('click', () => {
    offset+=10
    removePokemonsItems()
    offset >= 10 ? prev.classList.remove('hidden') : prev.classList.add('hidden')
    loadPokemonItens(offset)
  }) 
  
  prev.addEventListener('click', () => {
    offset-=10
    removePokemonsItems()
    loadPokemonItens(offset)
  })
  
  function removePokemonsItems(){
    pokemonList.innerHTML = ''
  }

  function loadPokemonItens(offset) {
    offset > 10 ? prev.classList.remove('hidden') : prev.classList.add('hidden')
    pokeAPI.getPokemons(offset).then((pokemons = []) => {
      pokemons.map(createPokemonItem)
    })  
  }
  
  loadPokemonItens(offset)
}


function createPokemonItem(pokemon) {
  id = pokemon.id < 10 ? `00${pokemon.id}` : pokemon.id < 100 ? `0${pokemon.id}` : pokemon.id
  
  function getPokemon() {
    pokeAPI.getPokemon(pokemon.id).then((pokemon) => {
      const html = createPokemonDetails(pokemon)
    })
    detailsModal.classList.remove('hidden')
  }

  const li = document.createElement('li')
  li.classList.add(`bg-${pokemon.types[0].type.name}-500`, 'flex', 'flex-col', 'rounded-2xl', 'p-3', 'max-w-[224px]')
  const span = document.createElement('span')
  span.classList.add(`text-${pokemon.types[0].type.name}-800`, 'font-semibold', 'self-end', 'capitalize')
  span.innerText = id
  li.appendChild(span)
  const h3 = document.createElement('h3')
  h3.classList.add('flex', 'justify-between', 'capitalize', 'font-semibold')
  h3.innerText = pokemon.name
  li.appendChild(h3)
  const divContainer = document.createElement('div')
  divContainer.classList.add('grid', 'grid-cols-2')
  const divContent = document.createElement('div')
  divContent.classList.add('flex', 'flex-col', 'justify-center')
  divContent.innerHTML = `${pokemon.types.map(type => `<span class="bg-${type.type.name}-300 px-2 py-1 w-fit rounded-2xl mb-1 text-zinc-100 font-bold">${type.type.name}</span>`).join('')}`
  const btnDetails = document.createElement('button')
  btnDetails.addEventListener('click', getPokemon)
  btnDetails.innerHTML = `<img src="${pokemon.sprites.other.dream_world.front_default}" alt="${pokemon.name}" class="w-28 h-28 self-end transform transition duration-500 hover:scale-125">`
  divContainer.appendChild(divContent)
  divContainer.appendChild(btnDetails)
  li.appendChild(divContainer)

  pokemonList.appendChild(li)
  return li
}

function createPokemonDetails(pokemon) {
  const id = pokemon.id < 10 ? `00${pokemon.id}` : pokemon.id < 100 ? `0${pokemon.id}` : pokemon.id

  const span = modalContent.querySelector('[data-js="pokemon-id"]')
  span.innerText = `#${id}`

  const img = modalContent.querySelector('[data-js="pokemon-img"]')
  img.src = pokemon.sprites.other.dream_world.front_default
  img.alt = pokemon.name

  const header = modalContent.querySelector('[data-js="pokemon-header"]')
  header.classList.add(`bg-${pokemon.types[0].type.name}-300`)

  const h2 = modalContent.querySelector('[data-js="pokemon-name"]')
  h2.innerText = pokemon.name

  const hp = modalContent.querySelector('[data-js="hp"]')
  hp.innerText = pokemon.stats[0].base_stat
  const hpBar = modalContent.querySelector('[data-js="hp-bar"]')
  hpBar.classList.add(`w-[${pokemon.stats[0].base_stat}%]`)
  hpPercentage = pokemon.stats[0].base_stat
  
  const attack = modalContent.querySelector('[data-js="attack"]')
  attack.innerText = pokemon.stats[1].base_stat
  const attackBarPercentage = modalContent.querySelector('[data-js="attack-percentage"]')
  attackBarPercentage.classList.add(`w-[${pokemon.stats[1].base_stat}%]`)
  attackPercentage = pokemon.stats[1].base_stat
  
  const defense = modalContent.querySelector('[data-js="defense"]')
  defense.innerText = pokemon.stats[2].base_stat
  const defenseBarPercentage = modalContent.querySelector('[data-js="defense-percentage"]')
  defenseBarPercentage.classList.add(`w-[${pokemon.stats[2].base_stat}%]`)
  defensePercentage = pokemon.stats[2].base_stat

  const specialAttack = modalContent.querySelector('[data-js="special-attack"]')
  specialAttack.innerText = pokemon.stats[3].base_stat
  const specialAttackBarPercentage = modalContent.querySelector('[data-js="special-attack-percentage"]')
  specialAttackBarPercentage.classList.add(`w-[${pokemon.stats[3].base_stat}%]`)
  specialDefensePercentage = pokemon.stats[3].base_stat

  const specialDefense = modalContent.querySelector('[data-js="special-defense"]')
  specialDefense.innerText = pokemon.stats[4].base_stat
  const specialDefenseBarPercentage = modalContent.querySelector('[data-js="special-defense-percentage"]')
  specialDefenseBarPercentage.classList.add(`w-[${pokemon.stats[4].base_stat}%]`)
  specialDefensePercentage = pokemon.stats[4].base_stat

  const speed = modalContent.querySelector('[data-js="speed"]')
  speed.innerText = pokemon.stats[5].base_stat
  const speedBarPercentage = modalContent.querySelector('[data-js="speed-percentage"]')
  speedBarPercentage.classList.add(`w-[${pokemon.stats[5].base_stat}%]`)
  speedPercentage = pokemon.stats[5].base_stat

  return modalContent
} 

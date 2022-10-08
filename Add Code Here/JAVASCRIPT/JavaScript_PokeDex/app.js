window.onload = () => {
    document.querySelector('input').value = '';
}

let keyword = document.querySelector('#keyword');
let btn = document.querySelector('#btn');

let getPokemon = async term => {
    let url = `https://pokeapi.co/api/v2/pokemon/${term}`;
    let response = await fetch(url);

    if (keyword.value == '') {
        alert('Please enter a valid Pokemon name');
        window.location.reload();
        return
    } else if (response.status == 404 || response.statusText == 'Not Found') {
        alert('Please enter a valid Pokemon name');
        window.location.reload();
        return
    }

    let pokemon = await response.json();
    debugger

    document.querySelector('img').setAttribute('src', `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/official-artwork/${pokemon.id}.png`);
    document.querySelector('.number').innerHTML = `#${pokemon.id.toString().padStart(3, '0')}`;
    document.querySelector('.name').innerHTML = pokemon.name;
    document.querySelector('.type1').innerHTML = `${pokemon.types[0].type.name}`;
    document.querySelector('.type2').innerHTML = `${pokemon.types[1].type.name}`;
}

btn.addEventListener('click', () => getPokemon(keyword.value.toLowerCase()));

keyword.addEventListener('keydown', e => {
    if (e.keyCode == 13) {
        getPokemon(keyword.value.toLowerCase());
    }
});
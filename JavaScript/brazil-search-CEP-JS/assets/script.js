const inputCep = document.querySelector('#cep')
const btn = document.querySelector('#btn')
const address = document.querySelector('#address')

function handleClick(e) {
  e.preventDefault();
  const cep = inputCep.value;
  getCep(cep)
}

function getCep(cep) {
  fetch(`https://viacep.com.br/ws/${cep}/json/`).then((r) => {
    return r.json()
  }).then((body) => {
    address.innerHTML = `<p>Logradouro: ${body.logradouro}</p><p>Bairro: ${body.bairro}</p><p>Cidade: ${body.localidade}</p><p>Estado: ${body.uf}</p>`
  })
}

btn.addEventListener('click', handleClick)


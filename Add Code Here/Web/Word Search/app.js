console.log('Hello');
str = "";

const fetchBtn = document.getElementById('fetchBtn');
const deleteBtn = document.getElementById('deleteBtn');

const inputtext = document.getElementById('inputtext');
const show = document.getElementById('list');

fetchBtn.addEventListener('click',getdata);
deleteBtn.addEventListener('click',deletedata);

function getdata(){

    const xhr = new XMLHttpRequest();

    xhr.open('GET',`https://mashape-community-urban-dictionary.p.rapidapi.com/define?term=${inputtext.value}`,true);
    xhr.setRequestHeader("x-rapidapi-key", "3713d5b39dmshf1764344d8244d5p116e9ajsneb81024be405");
    xhr.setRequestHeader("x-rapidapi-host", "mashape-community-urban-dictionary.p.rapidapi.com");

    xhr.onload = function(){
        const response = xhr.responseText;
        const obj = JSON.parse(response);
        // console.log(obj.list[0]);
        str = str + `<strong>${inputtext.value} </strong><li> ${obj.list[0].definition}</li> <br>`;
        show.innerHTML = str;
        // inputtext.value = "";
    }


    xhr.send();
}

function deletedata(){
show.innerHTML = "";
str = "";
}


const APIURL = 'https://api.github.com/users'
const btn = document.getElementById('btn')
const searchbar = document.getElementById('searchbar')


const getUser = async (username)=>{
    try{
        console.log('in try')
        
        const response = await axios.get(`https://api.github.com/users/${username}`);
        console.log(response.data)
        updatedata(response.data);
    }
    catch(e){
        console.log(e.name)
        console.log(e.message)
    }
}





function updatedata(data){
let filldata ='';
const div = document.createElement("div");


filldata = 
`
<div class = "card">
            <img src="${data.avatar_url}" alt="Error">
            <p class="bold">Bio</p>
            <p class="light">${data.bio}</p>
            <p class="bold">Locataion</p>
            <p class="light">${data.location}</p>
            <p class="bold">Number of Public Repos</p>
            <p class="light">${data.public_repos}</p>
            <p class="bold">Number of Followers</p>
            <p class="light">${data.followers}</p>
        
            <p class="light"><a href = "${data.blog}" class = "bold" target = "_blank" >LinkedIN</a></p>
</div>

`;

div.innerHTML = filldata;
div.classList.add('card')
const bottom = document.querySelector('.bottom').appendChild(div);

}




btn.addEventListener('click',()=>{
    const username = searchbar.value; 
    getUser(username);

})

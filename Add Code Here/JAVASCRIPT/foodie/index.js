const burger = document.querySelector('#burger');
const menu = document.querySelector('#menu');
const popular=document.querySelector('#popular');
const log=document.querySelector('#log');
const popup=document.querySelector('#popup');
burger.addEventListener('click', () => {
    if (menu.classList.contains('hidden')) {
        menu.classList.remove('hidden');


    } else {
        menu.classList.add('hidden');
    }
})
more.addEventListener('click',()=>{
    if(popular.classList.contains('hidden')){
       popular.classList.remove('hidden');
    }else{
        popular.classList.add('hidden')
    }
})
log.addEventListener('click', () => {
    if (popup.classList.contains('hidden')) {
        popup.classList.remove('hidden');
        


    } else {
        popup.classList.add('hidden');
    }
    
})
document.getElementById("login").addEventListener("click",validate);
        function validate()
        {
            var attempt=5;
            attempt--;
            var password = document.getElementById("Password").value;
            var username = document.getElementById("username").value;
            if(username == "admin" && password == "foodies"){
              alert ("Login Successfully");
              window.location="https://bit.ly/FooDIES";    //other page
              return false;
            }
            else{
              attempt--;
              alert("you have "+attempt+" attempt;");
              if(attempt==0){
                document.getElementById("username").disabled = true;
                 document.getElementById("password").disabled = true;
                 document.getElementById("login").disabled = true;
                 return false;
                }
            }
        }


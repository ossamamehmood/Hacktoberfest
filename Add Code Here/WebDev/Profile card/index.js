const changeFollowStatus=()=>{
    const ele=document.getElementById('followBtn')
    if(ele.textContent=="Following"){
        ele.textContent="Follow"
        ele.style.backgroundColor="transparent"
        ele.style.color="#02899C"
    }
    else{
        ele.textContent="Following"
        ele.style.backgroundColor="#03BFCB"
        ele.style.color="#1F1A36"
    }
}
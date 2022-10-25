'use strict';
function inputName()
{
    let name = "Would you like to enter your name?";
    if(confirm(name) == true)
    {
        let uname = window.prompt("Please enter your name", "user");
        if(uname != null)
        {
            alert(`Welcome ${uname} ! You have succesfully entered your name.`);
            document.getElementById("username").innerHTML = `Welcome ${uname} ! You have succesfully entered your name.`;
        }
        else
            alert("You declined entering your name.");
    }

    else
        alert("You pressed the cancel button.");
}

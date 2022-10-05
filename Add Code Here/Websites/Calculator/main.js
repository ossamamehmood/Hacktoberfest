let outputscreen = document.getElementById("output-screen");

function display(num){
	outputscreen.value += num;
}
function calculate(){
	try{
		outputscreen.value = eval(outputscreen.value);
	}
	catch(err)
	{
		alert("INVALID INPUT")
	}
}
function clr(){
	outputscreen.value = "";
}
function de(){
	outputscreen.value = outputscreen.value.slice(0,-1);
}
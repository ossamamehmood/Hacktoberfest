if (window.localStorage.getItem('id') == undefined) {
	window.localStorage.setItem('id',1);
}
function send(){
	var task = document.getElementById("task").value;
	var des = document.getElementById("des").value;
	var id = window.localStorage.getItem("id");
	if(task==""||des==""){
		window.alert("Please fill the empty blanks")
	}
	else {
	window.localStorage.setItem("task"+ id, task);
	window.localStorage.setItem("des"+ id, des);
	compo(task,des,id);
	id++;
	window.localStorage.setItem("id",id);
	document.getElementById("task").value = "";
	document.getElementById("des").value = "";
	}
}
function compo(task,des,id){
	var div = document.createElement("div");
	div.id = id;
	var h2 = document.createElement("h2");
	var hr = document.createElement("hr");
	var p = document.createElement("p");
	var button = document.createElement("button");
	h2.innerHTML = task;
	p.innerHTML = des;
	button.innerHTML = "Completed";
	button.onclick = function(){
		document.getElementById(id).style.display = "none";
		window.localStorage.removeItem("task" + id);
		window.localStorage.removeItem("des" + id);
	}
	div.append(h2,hr,p,button);
	document.getElementById("components").appendChild(div);
}
function loaded() {
	for(i=1; i<=100; i++) {
		if(window.localStorage.getItem("task"+i)== undefined){
			continue;
		}
		var task = window.localStorage.getItem("task"+i);
		var des = window.localStorage.getItem("des"+i);
		compo(task, des, i);
	}
		
}
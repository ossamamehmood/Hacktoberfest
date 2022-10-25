
fetch('https://codeforces.com/api/contest.list')
.then((alldata) => {
	return alldata.json();
})
.then((data) => {

		var displaydata = "";

		data.result.reverse();

		data.result.map((values)=>{
			if(values.phase == "BEFORE"){
				let time = new Date(values.startTimeSeconds*1000);
			displaydata+= `
				<div class="cards">
					 ${values.name}
					<p class="content"> Start Time : ${time.toDateString()}  &nbsp; ${time.toLocaleTimeString()}</p>
				</div>`;
		}
		});

		document.getElementById('codeforces').innerHTML += displaydata;
})


//---------------------------codechef-------------------------------


fetch('https://kontests.net/api/v1/code_chef')
.then((alldata) => {
	return alldata.json();
})
.then((data) => {
		var displaydata = "";

		data.pop();
		data.pop();

		data.reverse();

        data.map((values)=>{
			{
			displaydata+= `
			<div class="cards">
					 ${values.name}
					<p class="content"> Start Time : ${values.start_time} hours</p>
				</div>`;
		}
		});

		document.getElementById('codechef').innerHTML += displaydata;
})

//-----------------------------------leetcode------------------------------

fetch('https://kontests.net/api/v1/leet_code')
.then((alldata) => {
	return alldata.json();
})
.then((data) => {
		var displaydata = "";

		data.reverse();

        data.map((values)=>{
			{
			displaydata+= `
			<div class="cards">
					 ${values.name}
					<p class="content"> Start Time : ${values.start_time} hours</p>
				</div>`;
		}
		});

		document.getElementById('leetcode').innerHTML += displaydata;
})

var button=document.getElementsByTagName("button");

function func1(){
	var newlink=document.querySelector("link");
	newlink.href="style1.css";
	button[0].className="theme1 hide";
	button[1].className="theme2";
}

function func2(){
	var newlink=document.querySelector("link");
	newlink.href="style.css";
	button[0].className="theme1";
	button[1].className="theme2 hide";
}

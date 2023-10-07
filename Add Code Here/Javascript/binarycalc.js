var scr = ""; //declared as global v
function calculate() {
	if (scr.indexOf("+") != -1) {
		// If + is present in the string
		// String obtained from scr is split
		var num = scr.split("+");

		// The splitted string stores in num array
		var x = parseInt(num[0], 2);

		// The num[0] and num[1] are the two binary
		// numbers resp
		var y = parseInt(num[1], 2);
		var sum = x + y;
		var ans = sum.toString(2);
	} else if (scr.indexOf("-") != -1) {

		// If - is present in the string
		var num = scr.split("-");
		var x = parseInt(num[0], 2);
		var y = parseInt(num[1], 2);
		var sub = x - y;
		var ans = sub.toString(2);
	} else if (scr.indexOf("*") != -1) {

		// If * is present in the string
		var num = scr.split("*");
		var x = parseInt(num[0], 2);
		var y = parseInt(num[1], 2);
		var mul = x * y;
		var ans = mul.toString(2);
	} else if (scr.indexOf("/") != -1) {

		// If / is present in the string
		var num = scr.split("/");
		var x = parseInt(num[0], 2);
		var y = parseInt(num[1], 2);
		var div = x / y;
		var ans = div.toString(2);
	}
	scr = ans;
	document.getElementById("output").innerHTML = scr;

	function input(ch) {
		scr += ch;
		document.getElementById("output").innerHTML = scr;

		function backspace() {
			var b = document.getElementById("output").innerHTML;
			scr = b.substring(0, b.length - 1);
			document.getElementById("output").innerHTML = scr;

			function cls() {
				scr = "";
				document.getElementById("output").innerHTML = scr;
			}

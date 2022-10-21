<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
	  
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Calculator</title>
    

	<style type="text/css">
		.container
		{
			left: 25%;
			padding: 100px;
			text-align: center;
			border: 1px solid blue;
			
		}
		input, select {
  			width: 40%;
  			padding: 12px 20px;
  			margin: 8px 0;
  			display: inline-block;
  			border: 1px solid #ccc;
  			border-radius: 4px;
  			box-sizing: border-box;
		}

		input[type=submit] {
  			width: 5%;
 		 	background-color: #1E90FF;
  			color: white;
  			padding: 14px 20px;
  			margin: 8px 0;
  			border: none;
	 	 	border-radius: 4px;
  			cursor: pointer;
}
	</style>

    
    
  </head>
  <body>
	  

<?php


if(isset($_POST['operand'])){
	$number1=$_POST['number1'];
	$number2=$_POST['number2'];
	$operand=$_POST['operand'];
	if($operand=="+")
		$answer=$number1+$number2;
	else if($operand=="-")
		$answer=$number1-$number2;
	else if($operand=="x")
		$answer=$number1*$number2;
	else if($operand=="/")
		$answer=$number1/$number2;
		
		
}?>
<div class="container">
<form method="post" action="">
<h1>Simple Calculator</h1>
<br>
First Number:<input name="number1" value=""required>
<br>
Second Number:<input name="number2" value=""required>
<br>
<input type="submit" name="operand" value="+">
<input type="submit" name="operand" value="-">
<input type="submit" name="operand" value="x">
<input type="submit" name="operand" value="/">
<br>
<br>Result: <input type='text' value="<?php echo $answer; ?>"><br>
</form>
	</div>
</body>
</html>

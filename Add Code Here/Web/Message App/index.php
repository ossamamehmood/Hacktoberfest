<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Message App</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<h1>Kon'nichiwa watashi no yūjin</h1>

<h2>As most of us are anime fans..I think they would recognize this famous line :)</h2>

<h2> This is basically a open-to-all-linguistic messaging app ...Find interesting !! Start with a chat</h2>

<form action="" method="POST">

   <p>Start A New Chat :)</p>
   <label> <h3>UserName: </h3>
    <input type="text" name="Name" class="Input" style="width: 225px" placeholder="For eg : Dark Runner" required="">
   </label>
   <br><br>
   <label> <h3>Feedback  :</h3>
    <textarea name="Comment" class="Input" style="width: 1400px" placeholder="Drop out a comment " required=""></textarea>
   </label>
   <br><br>
   
   <input type="submit" name="Submit" value="Submit" class="Submit">
   <input type="submit" name="Submit" value="Reply" class="Submit">

  </form>

</body>
</html>
<?php
 
 if($_POST['Submit']){

  $Name = $_POST['Name'];
  $Comment = $_POST['Comment'];

  $old = fopen("comments.txt", "r+t");
  $old_comments = fread($old, 1024);

  $write = fopen("comments.txt", "w+");//mainly for appending comments in igniter website
  $string = "<b><h2>".$Name."</b><br><h4>".$Comment."<br>".$old_comments;
  fwrite($write, $string);
  fclose($write);
  fclose($old);
 }

 $read = fopen("comments.txt", "r+t");//reading old comments
 echo "<br><br>Comments<hr>".fread($read, 1024);
 fclose($read);

?>



    









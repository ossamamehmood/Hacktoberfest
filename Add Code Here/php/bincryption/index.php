<?php
require_once('Bincryption.php');
$text='iloveyou';
echo $text;
echo '<br/> <h1> encrypted text</h1>';
$crypt = new Bincryption();
echo $crypt->encode($text);
echo "<h2> done encryption</h2>";
echo $crypt->decode("ThAwCBNcxWtEzTEl6XCAliB0+zkKr3nCcYB7CSVu6E8=");
?>
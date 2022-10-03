<?php

$number = 7;

$result = 0;
$temp = 1;
$temp2 = 1;

for ($i=0; $i < $number; $i++) { 
    $temp2 = $result;
    $result += $temp;
    $temp = $temp2;
}

echo $result . "\n";

?>

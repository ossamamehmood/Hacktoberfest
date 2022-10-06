<?php
// Sum the values that come in,
// If they are the same value, triple them!
function sumOrTriple($x, $y) 
{
    return $x == $y ? ($x + $y)*3 : $x + $y;
}
echo sumOrTriple(1, 2)."\n";
echo sumOrTriple(3, 2)."\n";
echo sumOrTriple(2, 2)."\n"; 
?>

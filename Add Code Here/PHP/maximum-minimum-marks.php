<?php
$marks1 = array(360,310,310,330,313,375,456,111,256); 
$marks2 = array(350,340,356,330,321); 
$marks3 = array(630,340,570,635,434,255,298); 

$max_marks = max(max($marks1),max($marks2),max($marks3)); 
$min_marks = min(min($marks1),min($marks2),min($marks3));

echo "Maximum marks : ".$max_marks."\n";
echo "Minimum marks : ".$min_marks."\n";
?>
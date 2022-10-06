<?php
$x = 50;
$y = 100;

if ($x > $y) {
  $temp = $x;
  $x = $y;
  $y = $temp;
}

for($i = 1; $i < ($x+1); $i++) {
  if ($x%$i == 0 and $y%$i == 0)
    $hcf = $i;
}

echo "HCF of $x and $y is: $hcf";
?>
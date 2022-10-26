<?php
function print_number($count)
{
   
  $firstTerm=0;
  $secondTerm=1;
  
  //simpan string angka awal
  $result = "$firstTerm $secondTerm";
 
  for ($i=0; $i<$count-2; $i++)
  {
    // hitung angka fibonacci
    $output = $firstTerm + $secondTerm;
    // hasilnya ditambahkan ke string $hasil
    $result = $result." $output";
  
    //next increment
    $firstTerm = $secondTerm;
    $secondTerm = $output;
  }
  return $result;
}
  
echo print_number(8);
echo "<br>";
// result: 0 1 1 2 3 5 8 13
 
echo print_number(10);
echo "<br>";
// result: 0 1 1 2 3 5 8 13 21 34
 
echo print_number(20);
echo "<br>";
// result: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181
?>

<?php
function palindrome($no)
{
    $num = $no;
    $sum = 0;
    while (floor($num)) {
        $rem = $num % 10;
        $sum = $sum * 10 + $rem;
        $num = $num / 10;
    }
    return $sum;
}
$input = 12321;
$noum = palindrome($input);
if ($input == $noum) {
    echo $input . " is a Palindrome number";
} else {
    echo $input . " is not a Palindrome";
}

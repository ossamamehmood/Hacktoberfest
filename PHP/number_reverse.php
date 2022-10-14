<?php
$num = 12345;
$revNum = 0;
while ($num > 1) {
    $rem = $num % 10;
    $revNum = ($revNum * 10) + $rem;
    $num = ($num / 10);
}
echo "Reversed: " . $revNum;
?>

<!-- Result:: Reversed: 54321 -->
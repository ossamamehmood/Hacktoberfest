<?php
$year = 2000;
if ((0 == $year % 4) and (0 != $year % 100) or (0 == $year % 400)) {
    echo $year . " is a leap year";
} else {
    echo $year . " is not a leap year";
}

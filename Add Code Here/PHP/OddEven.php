<?php

function checkOddOrEven($num){
    if($num % 2 == 0){
        echo "Even"; 
    }
    else{
        echo "Odd";
    }
}
$num = 82;
checkOddOrEven($num)

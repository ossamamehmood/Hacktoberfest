<?php 

function custom_str_replace($find,$replace,$string){
$replaced = "";
for ($i=0; $i < strlen($string); $i++) { 
	
	if (strlen($find)>1) {

		if ($string[$i] == $find[0]) {

			$temp = "";
			for ($j=0; $j < strlen($find); $j++) { 

				if (!isset($string[$i+$j])) {
					// code...
				}else{
					$temp.=$string[$i+$j];
				}
			}
			if ($temp == $find) {

					$replaced.=$replace;

					$i=$i+strlen($find)-1;
				}else{
					$replaced .=$string[$i];
				}
		}else{

			$replaced .=$string[$i];
		}

	}else{

		if ($string[$i] == $find) {
			$replaced .=$replace; 

		}else{
			$replaced .=$string[$i]; 
		}
	}
}
	return $replaced;
}





$string = "This is a Long String";

$find = "String";

$replace = "Text";

echo "Before Custom Replace Function : ".$string;
echo "<br/>";
echo "<br/>";
echo "After Custom Replace Function : ".custom_str_replace($find,$replace,$string);;



?>

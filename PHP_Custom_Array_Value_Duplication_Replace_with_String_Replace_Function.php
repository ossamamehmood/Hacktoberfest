<?php
function custom_replace($find,$replace,$string){
$replaced = "";
for ($i=0; $i < strlen($string); $i++) { 
	if (strlen($find)>1) {
		if ($string[$i] == $find[0]) {
			$temp = "";
			for ($j=0; $j < strlen($find); $j++) { 
				if (isset($string[$i+$j])) {
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

$EmployeesNames =array(

				array('Classname'=>"Masroor Sommro Haider Solangi",'TwoClassname'=>array('Classname'=>"Kazim Ali Haider Solangi","childrens"=>array(
																															array('Classname'=>"Kazim Ali Haider Solangi",),
																															array('Classname'=>"Kiran Khan Haider Solangi"),
																															array('Classname'=>"Sanam Ali  Haider Solangi",)
																														)),'Deptname'=>"Masroor Sommro Haider Solangi","childrens"=>array(
																			array('Classname'=>"Kazim Ali Haider Solangi","childrens"=>array(
																															array('Classname'=>"Kazim Ali Haider Solangi",),
																															array('Classname'=>"Kiran Khan Haider Solangi"),
																															array('Classname'=>"Sanam Ali  Haider Solangi",)
																														)),
																	array('Classname'=>"Kiran Khan Haider Solangi"),
																	array('Classname'=>"Sanam Ali  Haider Solangi") 
																		)),
				array('Classname'=>"Ali Khan Haider Solangi",'Deptname'=>"Masroor Sommro Haider Solangi","childrens"=>array(
																	array('Classname'=>"Kazim Ali Haider Solangi",'Deptname'=>"Masroor Sommro Haider Solangi"),
																	array('Classname'=>"Kiran Khan Haider Solangi"),
																	array('Classname'=>"Sanam Ali  Haider Solangi") 
																		)),
				array('Classname'=>"Kamran  Mughsi Haider Solangi","childrens"=>array(
																	array('Classname'=>"Kazim Ali Haider Solangi"),
																	array('Classname'=>"Kiran Khan Haider Solangi"),
																	array('Classname'=>"Sanam Ali  Haider Solangi") 
																		)),
				array('Classname'=>"Zubair Ahmed Jatoi Haider Solangi"),
				array('Classname'=>"Masroor Sommro Haider Solangi","childrens"=>array(
																	array('Classname'=>"Kazim Ali Haider Solangi"),
																	array('Classname'=>"Kiran Khan Haider Solangi"),
																	array('Classname'=>"Sanam Ali  Haider Solangi") 
																		)),
				array('Classname'=>"Muhammad Ali Haider Solangi", "childrens"=>array(
																	array('Classname'=>"Kazim Ali Haider Solangi","childrens"=>array(
																	array('Classname'=>"Kazim Ali Haider Solangi"),
																	array('Classname'=>"Kiran Khan Haider Solangi"),
																	array('Classname'=>"Sanam Ali  Haider Solangi") 
																		)),
																	array('Classname'=>"Kiran Khan Haider Solangi"),
																	array('Classname'=>"Sanam Ali  Haider Solangi") 
																		)),
);

$new_array = array();
echo "<pre>";
echo "Old Array : zzzz";
echo "<br/>";
print_r($EmployeesNames);
echo "<br/>";
function replace_name_array($array)
{
	foreach ($array as $key => $value) {
		if (is_array($value)) {
			$new["$key"] = replace_name_array($value);
		}else{
			$value = custom_replace("Haider Solangi", "" , $value);
			$new["$key"] = $value;
		}
	}
		return $new;
}
$new_array = replace_name_array($EmployeesNames);

echo "<pre>";
echo "New Array : zzzz";
echo "<br/>";
print_r($new_array);
echo "<br/>";

die;
?>

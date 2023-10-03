import 'dart:io';
import 'dart:math';
 
void main(){
    //read number from user
    print('Enter x');
    var x = double.parse(stdin.readLineSync()!);
 
    var output = sqrt(x);
 
    print('sqrt(x) = $output');
}

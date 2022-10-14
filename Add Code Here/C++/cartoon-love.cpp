#include <iostream>
#include <string>

std::string Cartoon1(){
  std::string str ("Upin");
  str.erase(1);
  std::cout<<str;
  return str;
}

std::string Cartoon2(){
  std::string str ("Ipin");
  str.erase(1);
  std::cout<<str;
  return str;
}

void SpaceLetter(){
  std::cout<<"&";
}

void NewLine(){
  std::cout<<'\n';
}

int main(int argc, char *argv[]){
  for(int a=1; a<100; a++){
    std::string ResultCartoon = Cartoon1();
    SpaceLetter();
    std::string ResultCartoon2 = Cartoon2();
    NewLine();
  }
}


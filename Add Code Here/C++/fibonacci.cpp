#include <iostream>
using namespace std;
const string INFO = "Este programa imprime la sucesion de fibonacci desde \
1 hasta N, \nsiendo este ultimo un numero ingresado por el usuario\n";
int main() {
  unsigned long long aux = 1, fib = 0, lim, init;
  cout << INFO << endl;
  cout << "Ingrese un numero para la sucesion de fibonacci: ";
  cin >> lim;
  if(lim > 0) {
    for(init = 1; init <= lim; init++) {
      cout << "[" << fib << "] ";
      aux += fib; /* lo mismo que aux = aux + fib; */
      fib = aux - fib;
    }
  } else {
    cout << "El numero debe ser mayor a cero!!" << endl;
  }
  cout << "\n";
  return 0;
}
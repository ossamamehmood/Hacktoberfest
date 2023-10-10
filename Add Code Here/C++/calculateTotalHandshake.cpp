#include <iostream>
using namespace std;

int calTotalHandshake(int n) {
  if (n == 2)
    return 1;
  else {
    return (n - 1) + calTotalHandshake(n - 1);
  }
}

int main() {
  int n;
  cout << "Please enter the total persons: " << endl;
  cin >> n;
  cout << "Total Handshakes: " << calTotalHandshake(n);

  return 0;
}
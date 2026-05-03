#include<bits/stdc++.h>
using namespace std;

bool isPrime_bruteforce(int N) {
  for (int i = 2; i < N; i++) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}

bool isPrime_optimal(int N) {
  for (int i = 2; i < sqrt(N); i++) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 21;

  //bool ans = isPrime_bruteforce(n);
  bool ans = isPrime_optimal(n);
  if (n != 1 && ans == true) {
    cout << "Prime Number";
  } else {
    cout << "Non Prime Number";
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// accepted
// note primes count less then n
int countPrimes(int n) {
  vector<bool> isPrime(n+1, true);        
  int cnt = 0;
  isPrime[1] = false;
  for (int i=1; i<n; ++i) 
    if (isPrime[i] == true) {
      ++cnt;
      for(int j=2; i*j < n; ++j)
        isPrime[i*j] = false;
    }
  return cnt;
}

int main(int argc, char** argv) {
    return 0;
}

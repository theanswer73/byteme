#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

bool isAnagram(string s, string t) {
  if (s.size() != t.size())
    return false;     
  unordered_map<char, int> mp;
  for (int i=0; i<s.size(); ++i) {
    mp[s[i]]++;
    mp[t[i]]--;
  }
  for (auto it : mp)
    if (it.second > 0)
      return false;
  return true;
}

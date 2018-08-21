#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


class Solution {
public:
  int matrixScore(vector<vector<int>>& aa) {
    int n = sz(aa);
    int m = sz(aa[0]);
    fori (i, 0, n) {
      if (aa[i][0] == 0) {
        fori (j, 0, m)
          aa[i][j] ^= 1;  
      }
    }

    int res = 0;
    fori (j, 0, m) {
      int one = 0;
      fori (i, 0, n)
        if (aa[i][j] == 1) ++one;
      res += max(one, n - one) * (1 << (m - j - 1));
    } 
    return res;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p861-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  vvi aa = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
  cout << go.matrixScore(aa) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}

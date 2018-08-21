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


class DisjointSet
{
private:
  class Node {
  public:
    int val;
    int rank;
    Node* parent;
    Node(int inp)
      : val(inp) {
        parent = this;
        rank = 0;
      }
  };

public:
  void make_set(int inp) {
    Node* n = new Node(inp);
    dsets.pb(n);
    dset_size++;
  } 

  void joint(int x, int y) {
    link(find_set(x), find_set(y));
  }

  void link(Node* x, Node* y) {
    // trace("link", x->val, y->val);
    if (x->rank > y->rank)
      y->parent = x;
    else
      x->parent = y; 
    if (x->rank == y->rank)
      ++x->rank;
  }

  Node* find_set(int inp) {
    if (inp >= dset_size) {
      trace("Exceed the range of the DisjointSet.");
      return null;
    }
    return _find_set(dsets[inp]);
  }

  Node* _find_set(Node* x) {
    if (x != x->parent) {
      x->parent = _find_set(x->parent);
    }
    return x->parent;
  }

  int groups() {
    int res = 0;
    unordered_set<Node*> st;
    fora(node, dsets) {
      Node *par = _find_set(node);
      if (!st.count(par)) {
        ++res;
        st.insert(par);
      }
    }
    return res;
  }

private:
  vector<Node*> dsets;
  int dset_size;
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    DisjointSet djs;
    int n = sz(edges);
    fori (i, 0, n)
      djs.make_set(i);

    fora (e, edges) {
      if (djs.find_set(e[0] - 1) != djs.find_set(e[1] - 1))
        djs.joint(e[0] - 1, e[1] - 1);
      else 
        return e;
    } 
    return {};
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}

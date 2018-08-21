#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// TODO
int height(TreeNode* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void build(vector<vector<string>>& res, TreeNode* root, int h, int row,
        int lo) {
    if (!root) return ;
    int len = (1 << h-1) - 1;
    int col = lo + len;

    res[row][col] = to_string(root->val);
    build(res, root->left, h-1, row+1, lo);
    build(res, root->right, h-1, row+1, col+1);
} 

vector<vector<string>> printTree(TreeNode* root) {
    int r = height(root);
    int c = (1 << r) - 1;

    vector<vector<string>> res(r, vector<string>(c, ""));
    build(res, root, r, 0, 0); 
    return res;
}

int main(int argc, char** argv) {
    return 0;
}

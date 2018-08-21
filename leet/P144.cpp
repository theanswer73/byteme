#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

vector<int> res;
vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return res;
    res.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right); 
    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    if (!root) return res;

    stk.push(root);
    while (!stk.empty()) {
        TreeNode *top = stk.top();
        res.push_back(top->val);
        stk.pop();
        if (top->right) stk.push(top->right);
        if (top->left) stk.push(top->left);
    }
    return res;
}

int main(int argc, char** argv) {
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int dfs_height(TreeNode* root) {
    if (!root) return 0;
    return max(dfs_height(root->left), dfs_height(root->right)) + 1;
}

void preorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}

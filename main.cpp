//
//  main.cpp
//  Lab10
//
//  Created by Taanish Patel on 4/25/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
    
    void preorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
    }
    
    void postorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
    
    int dfs(TreeNode* node, int& diameter) {
        if (node == nullptr) return 0;
        int left_height = dfs(node->left, diameter);
        int right_height = dfs(node->right, diameter);
        diameter = max(diameter, left_height + right_height);
        return 1 + max(left_height, right_height);
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    
    vector<int> inorder;
    sol.inorderTraversal(root, inorder);
    cout << "Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> preorder;
    sol.preorderTraversal(root, preorder);
    cout << "Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> postorder;
    sol.postorderTraversal(root, postorder);
    cout << "Postorder Traversal: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;
    
    TreeNode* invertedRoot = sol.invertTree(root);
    
    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(invertedRoot) << endl;

    return 0;
}

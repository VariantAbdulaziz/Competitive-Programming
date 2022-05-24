// source: https://leetcode.com/problems/binary-tree-inorder-traversal/

// strategy: recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* node, vector<int>& answer){
        if(node){
            inOrder(node->left, answer);
            answer.push_back(node->val);
            inOrder(node->right, answer);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        
        return res;
    }
};
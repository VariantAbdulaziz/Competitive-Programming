// source: https://leetcode.com/problems/binary-tree-postorder-traversal/


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
    void postOrder(TreeNode* node, vector<int>& answer){
        if(node){
            postOrder(node->left, answer);
            postOrder(node->right, answer);
            answer.push_back(node->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        
        return res;
    }
};
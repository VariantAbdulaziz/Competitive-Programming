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
    TreeNode* helper(TreeNode* node){
        if(!node || (!node->left && !node->right)) {
            return node;
        }
        
        auto lefted = helper(node->left);
        auto righted = helper(node->right);
        if(lefted){
            auto temp = node->right;
            node->right = node->left;
            node->left = nullptr;
            lefted->right = temp;
        }
        return righted? righted: lefted;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};
// source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// strategy: recursion | bottom up
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *commonL{}, *commonR{};
        if(!root) return NULL;
        if(root->left) commonL = lowestCommonAncestor(root->left, p, q);
        if(root->right) commonR = lowestCommonAncestor(root->right, p, q);
        if(commonL && commonR) return root;
        if(root == q || root == p) return root;
        if(commonL || commonR) {
            if(commonL) return commonL;
            else if(commonR) return commonR;
        }
        return NULL;
    }
};
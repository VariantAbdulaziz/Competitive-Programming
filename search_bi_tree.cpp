// source: https://leetcode.com/problems/search-in-a-binary-search-tree/

// strategy: recursion \ binary search
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val) return root;
        
        if(root->val < val){
            TreeNode* r = searchBST(root->right, val);
            if(r) return r;
        }
        else if(root->val > val){
            TreeNode* l = searchBST(root->left, val);
            if(l) return l;
        }
        return NULL;
    }
};
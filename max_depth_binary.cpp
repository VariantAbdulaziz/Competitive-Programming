// source: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// strategy: recursion | bottom up approach
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left_ans = maxDepth(root->left);
        int right_ans = maxDepth(root->right);
        int ans_less_one = left_ans > right_ans? left_ans: right_ans;
        return ans_less_one + 1;
    }
};
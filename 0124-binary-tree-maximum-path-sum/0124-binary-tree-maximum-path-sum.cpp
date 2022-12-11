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
const int inf = 1e8;
class Solution {
public:
    int longestSumPath(int& answer, TreeNode* node){
        if(!node) return -inf;
        int left = longestSumPath(answer, node->left), right = longestSumPath(answer, node->right);
        answer = max(answer, max(left + right + node->val, max(max(left, right) + node->val, node->val)));
        return max(max(left, right) + node -> val, node->val);
    }
    int maxPathSum(TreeNode* root){
        int answer = -inf;
        longestSumPath(answer, root);
        return answer;
    }
};
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
    void helper(vector<vector<int>>* result_ptr, vector<int>* path_ptr, TreeNode* root, int target_sum, int path_sum) {
        auto &result = *result_ptr;
        auto &path = *path_ptr;
        if(!root) return;
        if(root && !root->left && !root->right) {
            path.push_back(root->val);
            if(path_sum + root->val == target_sum)
                result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        helper(&result, &path, root->left, target_sum, path_sum + root->val);
        helper(&result, &path, root->right, target_sum, path_sum + root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target_sum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(&result, &path, root, target_sum, 0);
        return result;
    }
};
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
    int rob(TreeNode* root) {
        map<tuple<TreeNode*, bool>, int> cache;
        return max(rob(cache, root, true), rob(cache, root, false));
    }
private:
    int rob(map<tuple<TreeNode*, bool>, int>& cache, TreeNode* root, bool gather){
        if(!root) return 0;
        if(cache.find({root, gather}) != cache.end()) return cache[{root, gather}];
        
        auto &res = cache[{root, gather}];
        if(gather){
            res = max(res, root->val + rob(cache, root->left, !gather) + rob(cache, root->right, !gather));
        } else {
            res = max(res, rob(cache, root->left, gather) + rob(cache, root->right, gather));
            res = max(res, rob(cache, root->left, !gather) + rob(cache, root->right, !gather));
            res = max(res, rob(cache, root->left, gather) + rob(cache, root->right, !gather));
            res = max(res, rob(cache, root->left, !gather) + rob(cache, root->right, gather));
        }
        return res;
    }
};
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
    map<int, map<int, vector<int>>> book;
public:
    void helper(TreeNode* node, int col, int row) {
        if(!node)
            return;
        helper(node->left, col - 1, row + 1);
        book[col][row].push_back(node->val);
        helper(node->right, col + 1, row + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        vector<vector<int>> result;
        for(auto &[_, val]: book) {
            result.push_back({});
            for(auto &[_, level]: val){
                auto &last = result.back();
                sort(begin(level), end(level));
                last.insert(end(last), begin(level), end(level));
            }
        }
        return result;
    }
};
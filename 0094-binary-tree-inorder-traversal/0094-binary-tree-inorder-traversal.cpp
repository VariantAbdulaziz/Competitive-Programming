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
/*
[1,2]
[3]
[3]

*/
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int> &result) {
        if(!root) return;
        
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, int>> recursion_stack;
        const int CALL = 0, RESUME = 1;
        
        recursion_stack.push(make_pair(root, CALL));
        while(!recursion_stack.empty()) {
            auto [now, action] = recursion_stack.top();
            recursion_stack.pop();
            if(action == CALL && now) {
                recursion_stack.push(make_pair(now->right, CALL));
                recursion_stack.push(make_pair(now, RESUME));
                recursion_stack.push(make_pair(now->left, CALL));
            } else if (action == RESUME && now) {
                result.push_back(now->val);
            }
        }
        return result;
    }
};
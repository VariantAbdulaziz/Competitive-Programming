// source: https://leetcode.com/problems/binary-tree-level-order-traversal/

// strategy: queue
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> lvl;
            for(int i=0; i < lvlSize; i++){
                
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                lvl.push_back(cur->val);
            }
            res.push_back(lvl);
            
        }
        return res;
    }
};
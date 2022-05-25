// source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// strategy: ad hoc solution
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
private:
    int search(vector<int>& inorder, int target, int start, int end){
        for(int i = start; i < end+1; i++){
            if (target == inorder[i])
                return i;
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int& rootIndex){
        
        if(start > end) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[rootIndex--]);
        if(start!=end){
            
            int divider = search(inorder, root->val, start, end);
            root->right = buildTree(inorder, postorder, divider+1, end, rootIndex);
            root->left = buildTree(inorder, postorder, start, divider-1, rootIndex);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIndex = inorder.size() - 1;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, rootIndex);
    }
};
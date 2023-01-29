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
class BSTIterator {
    vector<int> book;
    int itr = 0;
    void populate(TreeNode* root){
        if(!root) return;
        populate(root->left);
        book.push_back(root->val);
        populate(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        // populate(root);
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        while(!st.empty()){
            auto [node, is_update] = st.top();
            st.pop();
            if (is_update){
                book.push_back(node->val);
            }else if(node){
                st.push({node->right, 0});
                st.push({node, 1});
                st.push({node->left, 0});
            }
        }
    }
    
    int next() {
        return book[itr++];
    }
    
    bool hasNext() {
        return itr < book.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
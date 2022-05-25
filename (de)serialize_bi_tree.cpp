// source: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// strategy: level order traversal | queue | stack
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define SPACE ' '
#define N_WORD "NULL"
#define OPENNING_BRKT '['
#define CLOSING_BRKT ']'

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string str;
        q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            TreeNode* cur;
            stack<TreeNode*> st;
            stack<TreeNode*> next_lvl_st;
            while(lvl > 0){
                cur = q.front();
                st.push(cur);
                if(cur) str += to_string(cur->val);
                else str += N_WORD;
                str += SPACE;
                q.pop();
                lvl--;
            }
            while(!st.empty()){
                cur = st.top();
                st.pop();
                if(cur){
                    if(cur->right)
                        next_lvl_st.push(cur->right);
                    else //if(!next_lvl_st.empty())
                        next_lvl_st.push(NULL);
                    if(cur->left)
                        next_lvl_st.push(cur->left);
                    else if (!next_lvl_st.empty())
                        next_lvl_st.push(NULL);
                }
            }
            while(!next_lvl_st.empty()){
                q.push(next_lvl_st.top());
                next_lvl_st.pop();
            }
        }
        istringstream stream(str);
        string val;
        while(stream >> val) cout << val << SPACE;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream stream(data);
        string val;
        stream >> val;
        if(val == N_WORD) return NULL;
        TreeNode* root  = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            TreeNode* cur;
            while(lvl > 0){
                cur = q.front();
                if(cur){
                    if(stream >> val)
                        if(val != N_WORD)
                            cur->left = new TreeNode(stoi(val));
                    q.push(cur->left);
                    if(stream >> val)
                        if(val != N_WORD)
                            cur->right = new TreeNode(stoi(val));
                    q.push(cur->right);
                }
                q.pop();
                lvl--;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
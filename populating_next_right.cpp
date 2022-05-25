// source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// strategy: level order traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        
        if(root) q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            while(lvl > 0){
                Node* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (lvl - 1 > 0)
                    cur->next = q.front();
                lvl--;
            }
        }
        return root;
    }
};
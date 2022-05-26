// source: https://leetcode.com/problems/clone-graph/

// strategy: bfs | stack | hashmaps
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> book;
    
    Node* deepCopy(Node* node){
        
        stack<Node*> st;
        st.push(node);
        while(!st.empty()){
            Node* top = st.top(); st.pop();
            
            Node* clone = new Node(top->val);
            book[top] = clone;
            
            for(auto neighbor: top->neighbors){
                if(book.find(neighbor) == book.end())
                    st.push(neighbor);
            }
        }
        
        for(auto [orig, clone]: book){
            for(auto neighbor: orig->neighbors){
                
                clone->neighbors.push_back(book[neighbor]);
            }
        }
        return book[node];
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        
        return deepCopy(node);
    }
};
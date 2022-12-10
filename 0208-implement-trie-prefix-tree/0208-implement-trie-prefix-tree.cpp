class Node {
public:
    Node* children[26];
    bool isWord;
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto l: word){
            if(!curr->children[l - 'a'])
                curr->children[l - 'a'] = new Node();
            curr = curr->children[l - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto l: word){
            if(!curr->children[l - 'a'])
                return false;
            curr = curr->children[l - 'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto l: prefix){
            if(!curr->children[l - 'a'])
                return false;
            curr = curr->children[l - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
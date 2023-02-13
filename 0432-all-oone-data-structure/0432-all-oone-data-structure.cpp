class AllOne {
    const int inf = 1e9;
    map<string, int> book;
    map<int, set<string>> values;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(book.find(key) != book.end()){
            values[book[key]].erase(key);
            if(values[book[key]].empty())
                values.erase(book[key]);
        }
        book[key]++;
        values[book[key]].insert(key);
    }
    
    void dec(string key) {
        values[book[key]].erase(key);
        if(values[book[key]].empty())
            values.erase(book[key]);
        
        book[key]--;
        if(!book[key]){
            book.erase(key);
            return;
        }
        values[book[key]].insert(key);
    }
    
    string getMaxKey() {
        string ans = "";
        if(!values.empty()) {
            auto itr = values.end();
            itr--;
            ans = *((*itr).second.begin());
        }
        return ans;
    }
    
    string getMinKey() {
        string ans = "";
        if(!values.empty()) {
            auto itr = values.begin();
            ans = *((*itr).second.begin());
        }
    
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
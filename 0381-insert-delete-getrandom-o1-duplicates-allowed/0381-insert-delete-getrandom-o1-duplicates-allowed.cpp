class RandomizedCollection {
public:
    RandomizedCollection() {
    
    }
    
    bool insert(int val) {
        int idx = bucket.size();
        bucket.push_back(val);
        book[val].insert(idx);
        return book[val].size() == 1;
    }
    
    bool remove(int val) {
        if(book.find(val) == book.end()) return false;
        
        int last = bucket.size()-1;
        auto pivot = *book[val].begin();
        book[val].erase(pivot);
        
        swap(bucket[pivot], bucket[last]);
        
        book[bucket[pivot]].insert(pivot);
        book[bucket[pivot]].erase(last);
        bucket.pop_back();
        
        if(book[val].empty()) book.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return bucket[rand()%bucket.size()];
    }
    vector<int> bucket;
    unordered_map<int, unordered_set<int>> book;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
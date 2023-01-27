class RandomizedSet {
    map<int, int> book;
    vector<int> flatten_book;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(book.find(val) != end(book)){
            return false;
        }
        book[val] = flatten_book.size();
        flatten_book.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(book.find(val) == end(book)){
            return false;
        }
        auto last_elem = flatten_book.back();
        auto idx = book[val];
        swap(flatten_book[idx], flatten_book[flatten_book.size() - 1]);
        flatten_book.pop_back();
        book[flatten_book[idx]] = idx;
        book.erase(val);
        return true;
    }
    
    int getRandom() {
        return flatten_book[rand() % flatten_book.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
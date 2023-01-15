class LRUCache {
    int capacity;
    list<pair<int, int>> lru_cache;
    map<int, list<pair<int, int>>::iterator> book;
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if(book.find(key) != book.end()){
            lru_cache.splice(lru_cache.begin(), lru_cache, book[key]);
            return book[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(book.find(key) != book.end()){
            lru_cache.erase(book[key]);
            lru_cache.push_front(make_pair(key, value));
            book[key] = lru_cache.begin();
        } else {
            if(book.size() == capacity){
                auto [k, v] = lru_cache.back();
                lru_cache.pop_back();
                book.erase(k);
            }
            lru_cache.push_front(make_pair(key, value));
            book[key] = lru_cache.begin();
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
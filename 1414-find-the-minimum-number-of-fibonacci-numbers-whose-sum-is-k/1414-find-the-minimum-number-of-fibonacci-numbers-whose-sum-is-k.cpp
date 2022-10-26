class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> book{1, 1};
        map<int, int> cache;
        
        int x = 2;
        while(x <= k){
            book.push_back(x);
            x = book[book.size() - 1] + book[book.size() - 2];
        }
        return FibConstitution(cache, book, k);
    }
    
    int FibConstitution(map<int, int>& cache, vector<int> &book, int ki){
        if(cache.find(ki) != cache.end()) return cache[ki];
        
        auto &result = cache[ki];
        int station = 0;
        for(int jump = ki/2; jump > 0; jump /= 2){
            while(station + jump < book.size() && book[station + jump] <= ki)
                station += jump;
        }
        
        if(book[station] == ki) result = 1;
        else result = 1 + FibConstitution(cache, book, ki - book[station]);
        return result;
    }
};
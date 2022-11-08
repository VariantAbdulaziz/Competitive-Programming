class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> book;
        
        for(auto num: nums){
            auto itr = book.find(num);
            if(itr == book.end())
                book.insert(num);
            else
                book.erase(itr);
        }
        return vector<int>(begin(book), end(book));
    }
};
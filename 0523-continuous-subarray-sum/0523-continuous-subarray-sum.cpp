class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> book;
        int N = nums.size(), sum = 0;
        book[0] = -1;
        for(int i=0; i<N; i++){
            sum += nums[i];
            sum %= k;
            if(book.find(sum) != book.end() && i - book[sum] > 1){
                return true;
            } else if(book.find(sum) == book.end()){
                book[sum] = i;
            }
        }
        return false;
    }
};
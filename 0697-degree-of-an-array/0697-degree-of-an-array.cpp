class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> book, left, right;
        book.resize(50001);
        left.resize(50001);
        right.resize(50001);
        int result = 50001, n = nums.size();
        for(int i=0; i<n; i++) {
            if(!book[nums[i]]) left[nums[i]] = i;
            book[nums[i]]++;
            right[nums[i]] = i;
        }
        int frequent = *max_element(begin(book), end(book));
        for(auto num: nums) {
            if(book[num] == frequent) {
                result = min(result, right[num] - left[num] + 1);
            }
        }
        return result;
    }
};
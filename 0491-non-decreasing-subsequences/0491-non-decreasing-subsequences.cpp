class Solution {
private:
    vector<vector<int>> result;
    vector<int> stacked;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<int> book;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            if(!book.count(nums[i])) {
                book.insert(nums[i]);
                findSubsequences(nums, i);
            }
        }
        return result;
    }
    void findSubsequences(vector<int>& nums, int idx) {
        int N = nums.size();
        if(idx == N){
            if(stacked.size() > 1) result.push_back(stacked);
            return;
        }
        stacked.push_back(nums[idx]);
        set<int> book;
        for(int i = idx + 1; i <= N; i++){
            if(i == N || (!book.count(nums[i]) && nums[i] >= nums[idx])) {
                if(i < N) book.insert(nums[i]);
                findSubsequences(nums, i);
            }
        }
        stacked.pop_back();
    }
};
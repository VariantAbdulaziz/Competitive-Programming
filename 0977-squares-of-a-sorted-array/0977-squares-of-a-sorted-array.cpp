class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares(n);
        
        for(int i=0; i<n; i++) {
            squares[i] = nums[i] * nums[i];
        }
        sort(begin(squares), end(squares));
        return squares;
    }
};
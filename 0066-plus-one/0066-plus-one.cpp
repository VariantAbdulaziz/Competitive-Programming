class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(begin(digits), end(digits));
        int carry = 1;
        for(auto &digit: digits){
            digit += carry;
            carry = digit / 10;
            digit %= 10;
        }
        if(carry)
            digits.push_back(carry);
        reverse(begin(digits), end(digits));
        return digits;
    }
};
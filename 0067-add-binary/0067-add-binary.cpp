class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0, n = a.size(), m = b.size();
        for(int l=n-1, r=m-1; l >=0 || r >= 0 || carry; l--, r--){
            int curr = 0;
            if(l >= 0) curr += a[l] - '0';
            if(r >= 0) curr += b[r] - '0';
            curr += carry;
            carry = curr / 2;
            curr %= 2;
            result.push_back('0' + curr);
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};
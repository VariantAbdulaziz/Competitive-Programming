class Solution {
public:
    int strStr(string haystack, string needle) {
        const int BASE = 10, MOD = 31;
        int power = 1, needle_hash = 0, haystack_hash = 0;
        
        for(int i=0; i<needle.size(); i++){
            if(i>0)power = (power * BASE) % MOD;
            needle_hash = (BASE * needle_hash + (needle[i] - 'a' + 1)) % MOD;
            haystack_hash = (BASE * haystack_hash + (haystack[i] - 'a' + 1)) % MOD;
        }
        for(int i = needle.size(); i <= haystack.size(); i++){
            if(needle_hash == haystack_hash 
               && !haystack.compare(i - needle.size(), needle.size(), needle)) {
                
                return i - needle.size();
            }
            
            // update haystack hash
            haystack_hash = (haystack_hash - (haystack[i - needle.size()] - 'a' + 1) * power) % MOD;
            haystack_hash = (BASE * haystack_hash + (haystack[i] - 'a' + 1)) % MOD;
            if(haystack_hash < 0){
                haystack_hash += MOD;
            }
        }
        return -1;
    }
};
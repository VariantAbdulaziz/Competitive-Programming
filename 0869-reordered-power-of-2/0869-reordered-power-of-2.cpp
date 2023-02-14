class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str_n = to_string(n);
        sort(str_n.begin(), str_n.end());
        do {
            if(str_n[0] != '0') {
                int order = stoi(str_n);
                if(__builtin_popcount(order) == 1) return true;
            }
        } while(next_permutation(begin(str_n), end(str_n)));
        return false;
    }
};
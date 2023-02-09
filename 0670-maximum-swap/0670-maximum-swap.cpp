class Solution {
public:
    int maximumSwap(int num) {
        string num_string = to_string(num);
        int result = num, n = num_string.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(num_string[i], num_string[j]);
                result = max(result, stoi(num_string));
                swap(num_string[i], num_string[j]);
            }
        }
        return result;
    }
};
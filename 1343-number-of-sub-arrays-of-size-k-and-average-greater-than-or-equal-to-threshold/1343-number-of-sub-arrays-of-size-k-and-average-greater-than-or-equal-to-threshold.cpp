class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0, run = 0;
        for(int i = 0; i + 1 < k; i++){
            run += arr[i];
        }
        for(int l = 0, r = k - 1; r < arr.size(); l++, r++){
            run += arr[r];
            count += run / k >= threshold? 1: 0;
            run -= arr[l];
        }
        return count;
    }
};
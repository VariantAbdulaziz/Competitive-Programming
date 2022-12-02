class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int result = 0;
        for(int l=0, r; l < arr.size(); l = max(l + 1, r - 1)) {
            r = l + 1;
            while(r < arr.size() && arr[r-1] < arr[r]){
                r++;
            }
            int peak = r - 1;
            while(r < arr.size() && arr[r-1] > arr[r]){
                r++;
            }
            if(peak + 1 != r && l != peak){
                result = max(result, r - l);
            }
        }
        return result;
    }
};
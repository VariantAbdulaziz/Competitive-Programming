class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int result = 0;
        for(int l=0, r=1; r < arr.size(); l = r - 1){
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
            while(r < arr.size() && arr[r - 1] == arr[r])
                r++;
        }
        return result;
    }
};
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<vector<int>> window;
        for(int r=0; r<arr.size(); r++){
            window.push({(abs(arr[r] - x)), r});
            
            if(window.size() > k) window.pop();
        }
        vector<int> result;
        while(!window.empty()){
            result.push_back({arr[window.top()[1]]});
            window.pop();
        }
        sort(all(result));
        return result;
    }
};
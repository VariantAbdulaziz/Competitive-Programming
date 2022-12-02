class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // brute force complexity o(n^3)
        int result = 0;
        const int mod = 1e9 + 7;
        auto in_bound = [](int num, int a, int b){
            return num >= a && num < b;
        };
        
        for(int i = 0; i < arr.size(); i++){
            vector<int> book(101);
            
            for(int k = i + 1; k < arr.size(); k++){
                int promised = target - arr[i] - arr[k];
                if(in_bound(promised, 0, 101)){
                    result += book[promised];
                    result %= mod;
                }
                book[arr[k]]++;
            }
        }
        return result;
    }
};
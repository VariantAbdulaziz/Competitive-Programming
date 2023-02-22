class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0, n = time.size();
        vector<int> book(60 + 1);
        for(int i=0; i<n; i++) {
            auto now = time[i] % 60;
            result += book[(60 - now) % 60];
            book[now]++;
        }
        return result;
    }
};
class Solution {
public:
    long long numberOfWays(string s) {
        int N = s.size();
        long long number_of_ways = 0;
        vector<long long> middle(2), first_order(2); 
        for(int i = 0; i < N; i++){
            number_of_ways += middle['1' - s[i]];
            middle[s[i] - '0'] += first_order['1' - s[i]];
            first_order[s[i] - '0']++;
        }
        return number_of_ways;
    }
};
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int threshold = tickets[k], time = 0, n = tickets.size();
        for(int i=0; i<n; i++) {
            if(i <= k)
                time += min(threshold, tickets[i]);
            else time += min(threshold - 1, tickets[i]);
        }
        return time;
    }
};
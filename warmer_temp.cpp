// source: https://leetcode.com/problems/daily-temperatures/

// strategy: monotonic stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int> > st;
        
        st.push({temperatures[0], 0});
        for(int i = 1; i < temperatures.size(); i++){
            
            while(!st.empty() && temperatures[i] > st.top().first){  
                res[st.top().second] = i - st.top().second;
                st.pop();
             }
            st.push({temperatures[i], i});
        }
        return res;
    }
};
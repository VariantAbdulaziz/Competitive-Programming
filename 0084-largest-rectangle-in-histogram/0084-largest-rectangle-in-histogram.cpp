class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size(), result = 0;
        vector<int> left(N), right(N);
        stack<int> mono;
        for(int i=0; i<N; i++){
            while(!mono.empty() && heights[i] < heights[mono.top()]){
                right[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }
        while(!mono.empty()){
            right[mono.top()] = N;
            mono.pop();
        }
        for(int i=N-1; i>=0; i--){
            while(!mono.empty() && heights[i] < heights[mono.top()]){
                left[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }
        while(!mono.empty()){
            left[mono.top()] = -1;
            mono.pop();
        }
        for(int i=0; i < N; i++){
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        }
        return result;
    }
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int window = 0, result = k, N = blocks.size();
        for(int i=0; i<N; i++) {
            window += blocks[i] == 'B'? 1: 0;
            if (i + 1 >= k) {
                result = min(result, k - window);
                window -= blocks[i - k + 1] == 'B'? 1: 0;
            }
        }
        return result;
    }
};
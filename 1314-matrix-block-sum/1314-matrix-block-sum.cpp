class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int N = mat.size(), M = mat[0].size();
        vector<vector<int>> prefix_sum(N + 1, vector<int>(M + 1));
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= M; c++) {
                prefix_sum[r][c] = mat[r - 1][c - 1] 
                                 + prefix_sum[r - 1][c] 
                                 + prefix_sum[r][c - 1] 
                                 - prefix_sum[r - 1][c - 1];
            }
        }
        vector<vector<int>> matrix_block_sum(N, vector<int>(M));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                int top_r = max(0, r - k), left_c = max(0, c - k);
                int bottom_r = min(N, r + k + 1), right_c = min(M, c + k + 1);
                matrix_block_sum[r][c] = prefix_sum[bottom_r][right_c] 
                                       - prefix_sum[bottom_r][left_c] 
                                       - prefix_sum[top_r][right_c] 
                                       + prefix_sum[top_r][left_c];
            }
        }
        return matrix_block_sum;
    }
};
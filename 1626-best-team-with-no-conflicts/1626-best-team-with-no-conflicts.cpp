class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int best_team_score = 0, N = ages.size();
        vector<vector<int>> zipped_data(N, {0, 0});
        for(int i=0; i<N; i++) {
            zipped_data[i][0] = ages[i];
            zipped_data[i][1] = scores[i];
        }
        sort(begin(zipped_data), end(zipped_data));
        vector<int> dp(N);
        for(int i=0; i<N; i++){
            dp[i] = zipped_data[i][1];
            for(int j=0; j<i; j++){
                if(zipped_data[j][1] <= zipped_data[i][1]) {
                    dp[i] = max(dp[i], dp[j] + zipped_data[i][1]);
                }
            }
            best_team_score = max(best_team_score, dp[i]);
        }
        return best_team_score;
    }
};
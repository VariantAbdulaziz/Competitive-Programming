class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int N = plantTime.size();
        vector<vector<int>> zipped_data(N, {0, 0});
        for(int i=0; i<N; i++){
            zipped_data[i][0] = growTime[i];
            zipped_data[i][1] = plantTime[i];
        }
        sort(rbegin(zipped_data), rend(zipped_data));
        int earliest_full_bloom = 0, time = 0;
        for(int i=0; i<N; i++) {
            int plant_time = zipped_data[i][1];
            int grow_time = zipped_data[i][0];
            earliest_full_bloom = max(earliest_full_bloom, time + plant_time + grow_time);
            time += plant_time;
        }
        return earliest_full_bloom;
    }
};
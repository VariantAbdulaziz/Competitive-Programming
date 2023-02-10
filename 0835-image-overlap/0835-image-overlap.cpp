class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), m = img2.size();
        
        vector<pair<int, int>> book1, book2;
        map<pair<int, int>, int> shift_count;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(img1[i][j]) {
                    book1.push_back(make_pair(i, j));
                }
                if(img2[i][j]) {
                    book2.push_back(make_pair(i, j));
                }
            }
        }
        int result = 0;
        for(auto [r, c]: book1) {
            for(auto [r2, c2]: book2) {
                auto shift = make_pair(r-r2, c-c2);
                shift_count[shift] += 1;
                result = max(result, shift_count[shift]);
            }
        }
        
        return result;
    }
};
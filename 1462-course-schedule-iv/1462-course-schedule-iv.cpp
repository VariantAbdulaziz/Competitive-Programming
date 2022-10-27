class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        deque<deque<bool>> connections(numCourses, deque<bool>(numCourses, false));
        
        for(auto edge: prerequisites){
            int a = edge[0], b = edge[1];
            connections[a][b] = true;
        }
        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    connections[i][j] = connections[i][j] || (connections[i][k] && connections[k][j]);
                }
            }
        }
        vector<bool> result(queries.size());
        int query_no = 0;
        for(auto query: queries){
            int u = query[0], v = query[1];
            result[query_no++] = connections[u][v];
        }
        return result;
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<char>> connections(numCourses, vector<char>(numCourses));
        
        for(auto edge: prerequisites){
            int a = edge[0], b = edge[1];
            connections[a][b] = 1;
        }
        for(int intermidiate=0; intermidiate<numCourses; intermidiate++){
            for(int pre=0; pre<numCourses; pre++){
                for(int course=0; course<numCourses; course++){
                    connections[pre][course] = connections[pre][course] ||
                                                (connections[pre][intermidiate] && connections[intermidiate][course]);
                }
            }
        }
        
        vector<bool> result; result.reserve(queries.size());
        for(auto query: queries){
            int u = query[0], v = query[1];
            result.push_back(connections[u][v]);
        }
        return result;
    }
};
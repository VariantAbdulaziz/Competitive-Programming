class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int TAKING = 1;
        const int TAKEN = 2;
        vector<vector<int>> adj(numCourses);
        vector<int> book(numCourses);
        vector<int> res;
        
        for(auto prerequisite: prerequisites)
            adj[prerequisite[0]].push_back(prerequisite[1]);
        
        
        auto cycle = [&](auto&& cycle, int course) -> bool {
            if(book[course] == TAKING)
                return true;
            if(book[course] == TAKEN)
                return false;
            book[course] = TAKING;
            for(auto pre: adj[course]){
                if(cycle(cycle, pre)) return true;
            }
            book[course] = TAKEN;
            res.push_back(course);
            return false;
        };
        for(int course=0; course<numCourses; course++){
            if(cycle(cycle, course))
                return {};
        }
        return res;
    }
};
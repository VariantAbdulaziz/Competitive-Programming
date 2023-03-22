class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> course, result;
        course.push_back(obstacles[0]);
        result.push_back(1);
        for(int i=1; i<obstacles.size(); i++) {
            int n = course.size();
            int l = 0, r = n - 1, best = n;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(course[mid] <= obstacles[i]) {
                    best = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            if(best + 1 < n) course[best + 1] = obstacles[i];
            else if(obstacles[i] < course[0]) {
                course[0] = obstacles[i];
                best = -1;
            }
            else course.push_back(obstacles[i]);
            result.push_back(best + 2);
        }
        return result;
    }
};
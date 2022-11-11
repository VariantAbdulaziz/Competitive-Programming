class Solution {
private:
    double slope(vector<int>& p, vector<int>& q){
        if((q[0] - p[0]) == 0)
            return numeric_limits<double>::max();
        return (double)(q[1] - p[1])/(q[0] - p[0]);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i=0; i<points.size(); i++){
            map<double, int> book;
            for(int j=0; j<points.size(); j++){
                if(i!=j)
                    result = max(result, ++book[slope(points[i], points[j])]);
            }
        }
        return result + 1;
    }
};
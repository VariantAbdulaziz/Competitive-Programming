class DetectSquares {
    map<int, map<int, int>> book;
    vector<pair<int, int>> points;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        book[point[0]][point[1]]++;
        points.push_back(make_pair(point[0], point[1]));
    }
    
    int count(vector<int> point) {
        int result = 0;
        for(auto &[x, y]: points) {
            if(!abs(x - point[0]) ||
               !abs(y - point[1]) ||
               abs(x - point[0]) != abs(y - point[1])) // not squares
                continue;
            
            result += (book[point[0]][y] * book[x][point[1]]);
        }
        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
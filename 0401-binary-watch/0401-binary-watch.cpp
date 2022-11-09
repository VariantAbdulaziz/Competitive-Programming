class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        res.clear();
        vector<int> visited(book.size());
        readBinaryWatch(visited, turnedOn, 0);
        sort(begin(res), end(res));
        return res;
    }
private:
    bool valid(vector<int>& visited){
        int hour = 0;
        for(int i=0; i<4; i++){
            hour += visited[i]? book[i]: 0;
        }
        if(hour >= 12) return false;
        int minute = 0;
        for(int i=4; i<book.size(); i++){
            minute += visited[i]? book[i]: 0;
        }
        if(minute >= 60) return false;
        return true;
    }
    string construct(vector<int>& visited){
        int hour = 0;
        for(int i=0; i<4; i++){
            hour += visited[i]? book[i]: 0;
        }
        int minute = 0;
        for(int i=4; i<book.size(); i++){
            minute += visited[i]? book[i]: 0;
        }
        return to_string(hour) + (to_string(minute).size() == 1? ":0": ":") + to_string(minute);
    }
    void readBinaryWatch(vector<int>& visited, int turnedOn, int idx){
        if(turnedOn < 0) return;
        if(idx==book.size() && !turnedOn && valid(visited)){
            res.push_back(construct(visited));
        }
        if(idx==book.size()) return;
        visited[idx] = 1;
        readBinaryWatch(visited, turnedOn-1, idx+1);
        visited[idx] = 0;
        readBinaryWatch(visited, turnedOn, idx+1);
    }
    vector<int> book = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
    vector<string> res;
    
};
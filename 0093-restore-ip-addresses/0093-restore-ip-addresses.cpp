class Solution {
private:
    bool valid(const string& s) {
        return s.size() < 4 && (s.size() == 1 || (s[0] != '0' && (s.size() < 3 || s <= "255")));
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int N = s.size();
        for(int i=1; i<N && i < 4; i++){
            string first = s.substr(0, i);
            if(!valid(first)) continue;
            for(int j=1; i+j < N &&  j < 4; j++){
                string second = s.substr(i, j);
                if(!valid(second)) continue;
                for(int k=1; i+j+k < N && k < 4; k++){
                    string third = s.substr(i+j, k);
                    string fourth = s.substr(i+j+k);
                    if(valid(third) && valid(fourth)){
                        result.push_back(first + "." + second
                                        + "." + third + "." + fourth);
                    }
                }
            }
        }
        return result;
    }
};
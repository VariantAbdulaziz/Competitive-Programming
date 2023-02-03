class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token, result;
        while(getline(ss, token, '/')) {
            if(token == "." || token == "");
            else if(!st.empty() && token == ".."){
                st.pop_back();
            } else if(token != "..") {
                st.push_back("/" + token);
            }
        }
        for(auto &file_or_dir: st){
            result += file_or_dir;
        }
        return result.empty()? "/": result;
        
    }
};
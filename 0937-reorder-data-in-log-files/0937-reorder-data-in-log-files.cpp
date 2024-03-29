class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int N = logs.size();
        int holder = N - 1;
        for(int seeker = N - 1; seeker >= 0; seeker--){
            string identifier, word;
            stringstream ss(logs[seeker]);
            ss >> identifier;
            ss >> word;
            if(all_of(word.begin(), word.end(), ::isdigit)){
                swap(logs[holder], logs[seeker]);
                holder--;
            }
        }
        sort(begin(logs), end(logs) - (N - holder - 1), [](auto &a, auto &b){
            stringstream ssa(a), ssb(b);
            string identifier_a, identifier_b, content_a, content_b;
            ssa >> identifier_a;
            content_a = a.substr(identifier_a.size() + 1);
            ssb >> identifier_b;
            content_b = b.substr(identifier_b.size() + 1);
            return content_a < content_b || (content_a == content_b && identifier_a <= identifier_b);
        });
        return logs;
    }
};
class Solution {
public:
    int dfs(map<string, int>& cache, set<string>& words, map<string, vector<string>>& adj, string &word) {
        auto &result = cache[word];
        if (result) {
            return result;
        }
        
        result = 1;
        for(auto &pre: adj[word]) {
            if(words.find(pre) != words.end())
                result = max(result, 1 + dfs(cache, words, adj, pre));
        }
        return result;
    }
    int longestStrChain(vector<string>& words) {
        map<string, vector<string>> adj;
        for(auto &word: words) {
            int n = word.size();
            for(int i=0; i<n; i++) {
                auto predecessor = word.substr(0, i) + word.substr(i+1);
                adj[word].push_back(predecessor);
            }
        }
        map<string, int> cache;
        set<string> words_set(words.begin(), words.end());
        int longest_str_chain = 1;
        for(auto &word: words) {
            longest_str_chain = max(longest_str_chain, dfs(cache, words_set, adj, word));
        }
        return longest_str_chain;
    }
};
class Solution {
    string build_space(int no){
        string space = "";
        for(int i=1; i<=no; i++) {
            space += " ";
        }
        return space;
    }
    string justify(string &line, int maxWidth) {
        int no_spaces = 0, n = line.size();
        for (int i=0; i<n; i++) {
            if (line[i] == ' ') {
                no_spaces++;
            }
        }
        int no_words = no_spaces + 1;
        int spaces = (maxWidth - n + no_spaces) / (no_spaces? no_spaces: 1);
        int leftover = (maxWidth - n + no_spaces) % (no_spaces? no_spaces: 1);
        if(!no_spaces) no_spaces++;
        stringstream ss(line);
        string result = "", word;
        while (ss >> word) {
            result += word + (no_spaces? build_space(spaces + (leftover-- > 0? 1: 0)): "");
            no_spaces--;
        }
        return result;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justified_lines;
        bool first = false;
        int no_words = 0;
        for (auto &word: words) {
            if (first && justified_lines.back().size() + word.size() < maxWidth) {
                auto &last_line = justified_lines.back();
                last_line += " " + word;
            } else {
                first = true;
                justified_lines.push_back(word);
                no_words = 0;
            }
        }
        int n = justified_lines.size();
        for (int i = 0; i + 1 < n; i++) {
            justified_lines[i] = justify(justified_lines[i], maxWidth);
        }
        int lastpad = maxWidth - justified_lines[n - 1].size();
        while (lastpad--){
            justified_lines[n-1] += " ";
        }
        return justified_lines;
    }
};
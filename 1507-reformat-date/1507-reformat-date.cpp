class Solution {
    map<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
                                  {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
                                  {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string token, dd, mm, yyyy;
        ss >> token;
        token.pop_back(); token.pop_back();
        if(token.size() == 1) token.insert(0, "0");
        dd = token;
        ss >> token;
        mm = months[token];
        ss >> yyyy;
        return yyyy + "-" + mm + "-" + dd;
    }
};
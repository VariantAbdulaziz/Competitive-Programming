class Solution {
    vector<string> lower_order = {
        "Zero", "One", "Two", "Three", "Four", "Five", 
        "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
        "Twelve", "Thirteen", "Fourteen", "Fifteen", 
        "Sixteen", "Seventeen", "Eighteen", "Nineteen",
    };
    map<int, string> higher_order = {
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
        {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {2, "Hundred"},
        {3, "Thousand"},{6, "Million"}, {9, "Billion"}
    };
public:
    string numberToWords(int num) {
        if(num < 20) {
            return lower_order[num];
        }
        string num_ = to_string(num);
        if(num < 100){
            return higher_order[(num_[0] - '0') * 10] + 
                    (num_[1] == '0'? "" : " " + numberToWords(num % 10));
        }
        
        if(num < 1000){
            int rest = num % ((num_[0] - '0') * 100);
            return lower_order[num_[0] - '0'] + " " + higher_order[num_.size()-1] + 
                    (rest? " " + numberToWords(rest): "");
        }
        auto mod = num_.size() % 3;
        auto initials = num_.substr(0, mod? mod: 3);
        auto rest = stoi(num_.substr(mod? mod: 3));
        auto degree = num_.size() - (mod? mod: 3);
        return numberToWords(stoi(initials)) + " " + higher_order[degree] + (rest? " " + numberToWords(rest): "");
    }
};
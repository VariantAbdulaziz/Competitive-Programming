class Solution {
public:
    bool valid(string token) {
        return token.size() < 4 && (token.size() == 1 || (token[0] != '0' && (token.size() < 3 || token <= "255")));
    }
    bool checkIP4(string queryIP) {
        stringstream ss(queryIP);
        string token;
        int tokens = 0;
        while(getline(ss, token, '.')){
            tokens++;
            if(token.size() < 1 || !all_of(begin(token), end(token), ::isdigit) || !valid(token)) {
                return false;
            }
        }
        return tokens == 4;
    }
    bool checkIP6(string queryIP) {
        stringstream ss(queryIP);
        string token;
        int tokens = 0;
        while(getline(ss, token, ':')){
            tokens++;
            if(token.size() < 1 || token.size() > 4 || !all_of(begin(token), end(token), [](auto ch){ return isdigit(ch) || isalpha(ch) && (ch >= 'A' && ch < 'G') || (ch >= 'a' && ch < 'g'); })) {
                return false;
            }
        }
        return tokens == 8;
    }
    
    string validIPAddress(string queryIP) {
        int ip4 = 0, ip6 = 0, neither = 0;
        for(auto ch: queryIP) {
            if(!isdigit(ch) && !isalpha(ch)){
                if(ch == '.')
                    ip4 += 1;
                else if(ch == ':')
                    ip6 += 1;
                else neither += 1;
            }
        }
        
        if(ip4 == 3 && !ip6 && !neither) return checkIP4(queryIP)? "IPv4" : "Neither";
        if(ip6 == 7 && !ip4 && !neither) return checkIP6(queryIP)? "IPv6" : "Neither";
        return "Neither";
    }
};
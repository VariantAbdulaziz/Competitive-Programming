class Solution {
    bool canBeRemoved(string& aux, int k){
        auto benchmark = aux.back();
        int l = aux.size() - k;
        while(k--){
            if(aux[l++] != benchmark)
                return false;
        }
        return true;
    }
public:
    string removeDuplicates(string s, int k) {
        string aux;
        for(auto ch: s){
            aux.push_back(ch);
            int len = aux.size();
            if(len >= k && canBeRemoved(aux, k)){
                for(int i=0; i<k; i++) aux.pop_back();
            }
        }
        return aux;
    }
};
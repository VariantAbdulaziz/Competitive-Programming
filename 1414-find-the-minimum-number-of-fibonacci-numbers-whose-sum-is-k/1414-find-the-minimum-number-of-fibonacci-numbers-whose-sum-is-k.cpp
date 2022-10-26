class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> book{1, 1};
        
        int x = 2;
        while(x <= k){
            book.push_back(x);
            x = book[book.size() - 1] + book[book.size() - 2];
        }
        return FibConstitution(book, k);
    }
    
    int FibConstitution(vector<int> &book, int ki){
        int station = 0;
        for(int jump = ki/2; jump > 0; jump /= 2){
            while(station + jump < book.size() && book[station + jump] <= ki)
                station += jump;
        }
        
        if(book[station] == ki) return 1;
        return 1 + FibConstitution(book, ki - book[station]);
    }
};
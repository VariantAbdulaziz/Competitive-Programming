class Solution {
public:
    int minimumBoxes(int n) {
        // place 1 on 1 level 0 + 1
        // place 3 on 2 level 1 + 2 
        // place 6 on 3 level 3 + 3
        // place 10 on 4 level 6 + 4
        // place 15 on 5 level 10 + 5
        int layer = 0;
        int total = 0;
        int i = 1;
        while(total < n){
            layer += i;
            total += layer;
            i++;
        }
        if(total == n){
            return layer;
        }
        total -= layer;
        layer -= i;

        i = 1;
        while(total < n){
            total += i;
            i++;
        }
        return layer + i;
    }
};
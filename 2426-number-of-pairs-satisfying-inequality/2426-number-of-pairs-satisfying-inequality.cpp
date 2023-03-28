class Solution {
public:
    long long numberOfPairs(vector<int>& A, vector<int>& B, int diff) {
        /*
        A[i] - A[j] <= B[i] - B[j] + diff
        A[i] - B[i] <= A[j] - B[j] + diff
        
        -2 * 10^4 <= A[j] - B[j] + diff <= 2 * 10^4
        ans += query(0, A[i] - B[i])
        add(1, A[j] - B[j] + diff)
        
        */
        int N = 6e4, M = A.size();
        auto ans = 0ll;
        vector<long long> tree;
        tree.resize(2 * N + 5);
        
        auto add = [&](int a, int j) {
            j += N;
            tree[j] += a;
            for (j = j/2; j > 0; j /= 2) {
                tree[j] = tree[2*j]+tree[2*j+1];
            }
        };
        
        auto query = [&](int a, int b) {
            a += N; b += N;
            int s = 0;
            while(a <= b) {
                if(a%2 == 1) s += tree[a++];
                if(b%2 == 0) s += tree[b--];
                a /= 2; b /= 2;
            }
            return s;
        };
        
        int offset = N/2;
        for(int i=0; i<M; i++) {
            ans += query(0, offset + A[i] - B[i] + diff);
            add(1, offset + A[i] - B[i]);
        }
        
        return ans;
    }
};
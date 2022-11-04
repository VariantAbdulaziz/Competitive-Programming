class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        vector<int> is_prime(n, 1);
        for(int i=2; i<n; i++){
            result += is_prime[i];
            if(is_prime[i])
                for(long long j=(long long)i*i; j<n; j+=i){
                    is_prime[j] = 0;
                }
        }

        return result;
    }
};
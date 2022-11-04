class Solution {
public:
    int countPrimes(int n) {
        
        vector<int> is_prime(n, 1);
        for(int i=2; i<n; i++){
            if(is_prime[i])
                for(long long j=(long long)i*i; j<n; j+=i){
                    is_prime[j] = 0;
                }
        }
        int result = 0;
        for(int i=2; i<n; i++){
            result += is_prime[i];
        }
        return result;
    }
};
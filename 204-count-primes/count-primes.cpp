class Solution {
public:
    vector<bool> sieve(int n){
        vector<bool>isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2; i*i<=n; i++){
            int j=2;
            while(i*j<=n){
                isprime[i*j]=false;
                j++;
            }
        }

        return isprime;

    }
    int countPrimes(int n) {
        vector<bool>isprime = sieve(n);
        int ans=0;
        for(int i=2; i<n; i++){
            if(isprime[i]) ans++;
        }

        return ans;
    }
};
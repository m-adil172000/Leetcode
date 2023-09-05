class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n,true);
        if(v.size()<3) return 0; // because we have to check upto less than n

        v[0]=v[1]=false;
        int count=1;

        for(int i=3; i<n; i+=2){//not checking even numbers bcz they are non-primes
            if(v[i]){
                count++;
                //only updating odd multiples of i bcz even multiples are non-prime
                for(int j=i*3 ; j<n; j+=i+i){
                    v[j]=false;
                }
            }
        }

        return count;
    }
    
};

/*
vector<bool> sieve(int n){
        vector<bool>isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2; i*i<=n; i+=2){ 
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
    // Time Complexity : O(n*log(log(n))
    // Space Complexity : O(n)


*/
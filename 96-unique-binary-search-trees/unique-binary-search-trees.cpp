class Solution {
public:

    int SolveDP(int n){
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;

        // Number of nodes that is value of n given
        for(int i=2; i<=n; i++){
            // Node which is taken as the root
            for(int j=1; j<=i; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }

        // T(n) = sum of (i=1 to n) {T(i-1)*T(n-i)}

        return dp[n];
    }

    int numTrees(int n) {
        return SolveDP(n);

        // can also be solved using catalan number
    }
};
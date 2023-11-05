class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(n+1,vector<int>(3,0));

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j==0){
                    dp[i][j] = max(-prices[i]+dp[i+1][1], dp[i+1][0]);
                }
                else{
                    if(i==n-1){
                        dp[i][j] = max(prices[i] + dp[i+1][0], dp[i+1][1]);
                        continue;
                    }
                    dp[i][j] = max(prices[i] + dp[i+2][0], dp[i+1][1]);
                }
            }
        }

        return dp[0][0];
    }
};
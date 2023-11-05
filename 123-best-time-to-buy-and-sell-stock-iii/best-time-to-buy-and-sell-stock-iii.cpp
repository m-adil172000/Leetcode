class Solution {
private:
    int solve(int i, int b, int t, vector<int> &prices, vector<vector<vector<int>>>&dp){
        if(t>2) return 0;
        if(i==prices.size()) return 0;

        if(dp[i][b][t] != -1) return dp[i][b][t];

        if(b==0){
            if(t<2){
                int buy = -prices[i] + solve(i+1,1,t,prices,dp);
                return dp[i][b][t] = max(buy, solve(i+1,0,t,prices,dp));
            }
        }
        else{
            if(t<=2){
                int sell = prices[i] + solve(i+1,0,t+1,prices,dp);
                return dp[i][b][t] = max(sell, solve(i+1,1,t,prices,dp));
            }
        }
        return 0;

    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int j=0; j<2; j++){
            for(int t=0; t<3; t++){
                dp[n][j][t]=0;
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<2; j++){
                dp[i][j][2]=0;
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int t=1; t>=0; t--){
                    if(j==0){
                        if(t<2){
                            dp[i][j][t]=  max(-prices[i]+dp[i+1][1][t] , dp[i+1][0][t]);
                        }
                    }
                    else{
                        if(t<=2){
                            dp[i][j][t] = max(prices[i] + dp[i+1][0][t+1], dp[i+1][1][t]);
                        }
                    }
                }
            }
        }

        return dp[0][0][0];


        return solve(0,0,0,prices,dp); 
    }
};
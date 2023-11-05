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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0,0,0,prices,dp); 
    }
};
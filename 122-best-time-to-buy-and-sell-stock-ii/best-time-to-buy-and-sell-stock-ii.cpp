class Solution {
private:
    int solve(int i ,int b,vector<int>&prices, vector<vector<int>>&dp){

        if(i==prices.size()){
            return 0;
        }

        if(dp[i][b] != -1) return dp[i][b];

        if(b==0){
            int profit = -prices[i] + solve(i+1,1,prices,dp);
            return dp[i][b] = max(profit, solve(i+1,b,prices,dp));
        }
        else{
            int sell = prices[i] + solve(i+1,0,prices,dp);
            return dp[i][b] =  max(sell, solve(i+1,b,prices,dp));
        }
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,buy,prices,dp);
    }
};
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
        vector<int>ahead(2,0),curr(2,0);
        ahead[0]=ahead[1]=0;

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
               if(j==0){
                    curr[j] = max(-prices[i] + ahead[1], ahead[0]);
                }
                else{
                    curr[j] =  max(prices[i] + ahead[0], ahead[1]);
                } 
            }
            ahead = curr;
        }

        return ahead[0];

    }
};
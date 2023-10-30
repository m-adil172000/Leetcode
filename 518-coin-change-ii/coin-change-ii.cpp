class Solution {
private:
    int solve(int amount, vector<int>&coins, int n, int idx,vector<vector<int>>&dp){
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(amount==0) return 1;

        if(idx==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }

        if(amount<0) return 0;

        int take=0;
        if(coins[idx]<=amount) take += solve(amount-coins[idx],coins,n,idx,dp);
        int not_take = solve(amount,coins,n,idx-1,dp);

        return dp[idx][amount]= take + not_take;

    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(amount,coins,n,n-1,dp);


    }
};
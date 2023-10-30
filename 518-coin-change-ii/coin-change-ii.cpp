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
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        for(int t=0; t<=amount; t++) dp[0][t]= (t%coins[0]==0);

        for(int i=1; i<n; i++){
            for(int t=0;t<=amount; t++){
                int take=0;
                if(coins[i]<=t) take += dp[i][t-coins[i]];
                int not_take = dp[i-1][t];

                dp[i][t] = take + not_take;
            }
        }

        return dp[n-1][amount];


    }
};
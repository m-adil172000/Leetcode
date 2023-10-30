class Solution {
private:
    int solve(int amount, vector<int>&coins, int n, int idx,vector<vector<int>>&dp){
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(amount==0) return 1;

        if(idx==0){
            if(amount%coins[0]==0) return 1;  //bcz we can take the oth coin any number of time to create the amount required
            else return 0;
        }

        if(amount<0) return 0;

        int take=0;
        //bcz we can take same coin any number of times so we don't decrease the index
        if(coins[idx]<=amount) take += solve(amount-coins[idx],coins,n,idx,dp);
        int not_take = solve(amount,coins,n,idx-1,dp);

        return dp[idx][amount]= take + not_take;

    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0),curr(amount+1,0);
        
        for(int t=0; t<=amount; t++) prev[t]= (t%coins[0]==0);

        for(int i=1; i<n; i++){
            for(int t=0;t<=amount; t++){
                int take=0;
                if(coins[i]<=t) take += curr[t-coins[i]];
                int not_take = prev[t];

                curr[t] = take + not_take;
            }
            prev=curr;
        }

        return prev[amount];


    }
};
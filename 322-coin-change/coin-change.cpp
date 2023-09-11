class Solution {
public:

    

    int coinChange(vector<int>& coins, int amount) {

        int ans=0, curr=0;
        

        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1; i<=amount; i++){
            for(auto it:coins){
                if(i - it >=0){
                    dp[i] = min(dp[i], 1+dp[i-it]);
                }
            }
        }

        if(dp[amount]==amount+1) return -1;
        else return dp[amount];
    }
};
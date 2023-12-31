class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();

        //vector<vector<int>>dp(n+1,vector<int>(5,0));

        /*
        B S B S
        0 1 2 3

        we can see that buy is an even number operation and sell is odd number operation
        */
        // we need not to write the base cases bcz they are already 0
        vector<int>after(5,0),curr(5,0);

        for(int i=n-1; i>=0; i--){
            for(int t=0; t<4; t++){
                if(t%2==0){
                    // Buy
                    curr[t] = max(-prices[i]+after[t+1], after[t]);
                }
                else{
                    //sell
                    curr[t] = max(prices[i] + after[t+1],after[t]);
                }
            }
            after = curr;
        }

        return after[0];
    }
};
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
        vector<vector<int>>after(2,vector<int>(3,0)), curr(2,vector<int>(3,0));

        //Because everything is already 0 so we don't have to write the base cases bcz the base cases will only try to put 0

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int t=1; t>=0; t--){
                    if(j==0){
                        if(t<2){
                            curr[j][t]=  max(-prices[i]+after[1][t] , after[0][t]);
                        }
                    }
                    else{
                        if(t<=2){
                            curr[j][t] = max(prices[i] + after[0][t+1], after[1][t]);
                        }
                    }
                }
            }
            after = curr;
        }

        return after[0][0];

    }
};
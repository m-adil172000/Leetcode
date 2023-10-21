class Solution {
private:
    int solve(vector<int>& days, vector<int>& costs, int i, int n,vector<int>&dp){

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int one = costs[0] + solve(days,costs,i+1,n,dp);

        int seven = costs[1];
        int up1 = lower_bound(days.begin()+i,days.end(),days[i]+7)-(days.begin()+i);
        seven += solve(days,costs,i+up1,n,dp);

        int thirty = costs[2];
        int up2 = lower_bound(days.begin()+i,days.end(),days[i]+30)-(days.begin()+i);
        thirty += solve(days,costs,i+up2,n,dp);

        return dp[i] = min({one,seven,thirty});

    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;

        for(int i=n-1; i>=0; i--){
            int one = costs[0] + dp[i+1];

            int seven = costs[1];
            int up1 = lower_bound(days.begin()+i,days.end(),days[i]+7)-(days.begin()+i);
            seven += dp[i+up1];

            int thirty = costs[2];
            int up2 = lower_bound(days.begin()+i,days.end(),days[i]+30)-(days.begin()+i);
            thirty += dp[i+up2];

            dp[i] = min({one,seven,thirty});

        }

        return dp[0];
    }
};
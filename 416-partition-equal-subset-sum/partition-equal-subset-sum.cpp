class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2!=0) return false;
        int n =nums.size();
        int k = sum/2;
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));

        for(int i=0; i<n; i++) dp[i][0]=true;

        if(nums[0]<=k) dp[0][nums[0]] =true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                bool take =false;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                bool nottake = dp[i-1][j];

                dp[i][j]=take||nottake;
            }
        }

        return dp[n-1][k];
    }
};
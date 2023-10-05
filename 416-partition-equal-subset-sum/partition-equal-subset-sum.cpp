class Solution {
private:
    bool solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==0){
            return nums[0]==target;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        bool take = false;
        if(nums[i]<=target){
            take = solve(i-1, target-nums[i], nums,dp);
        }
        bool nottake = solve(i-1,target,nums, dp);

        return dp[i][target]=  take||nottake;

        
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2!=0) return false;
        int n =nums.size();

        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return solve(n-1,sum/2, nums,dp);
    }
};
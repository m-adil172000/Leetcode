class Solution {
private:
    int solve(vector<int>&nums, int target, int ans,int i){

        if(i==0){
            if(ans+nums[i]==target && ans-nums[i]==target) return 2;
            if(ans+nums[i]==target || ans-nums[i]==target) return 1;
            else return 0;
        }

        int plus = solve(nums,target, ans+nums[i],i-1);
        int minus = solve(nums,target, ans-nums[i],i-1);

        return plus+minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int ans=0;
        int n = nums.size();
        return solve(nums, target,ans,n-1);
    }
};
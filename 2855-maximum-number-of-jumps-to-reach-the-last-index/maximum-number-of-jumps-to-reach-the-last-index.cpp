class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0]=0;
        if(abs(nums[1]-nums[0])<=target) dp[1]=1;
        else dp[1]=-1;

        for(int i=2; i<n; i++){
            int temp = INT_MIN;
            for(int j=0; j<i; j++){
                if(abs(nums[i]-nums[j]) <= target && dp[j]!=-1){
                    temp = max(temp, dp[j]);
                }
            }
            if(temp==INT_MIN) dp[i]=-1;
            else{dp[i]=1 + temp;}
        }

        return dp[n-1];
    }
};
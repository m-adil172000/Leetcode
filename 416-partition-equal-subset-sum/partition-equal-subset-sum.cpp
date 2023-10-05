class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2!=0) return false;
        int n =nums.size();
        int k = sum/2;
        vector<bool>prev(k+1,false), curr(k+1,false);

        curr[0]=prev[0]=true;

        if(nums[0]<=k) prev[nums[0]] =true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                bool take =false;
                if(nums[i]<=j) take = prev[j-nums[i]];
                bool nottake = prev[j];

                curr[j]=take||nottake;
            }
            prev = curr;
        }

        return prev[k];
    }
};
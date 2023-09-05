class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0;
        int n=nums.size();
        int sum=0;
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum<target) return 0;
        sum =0;

        while(r<n){
            sum += nums[r];

            if(sum>=target){
                ans = min(ans,(r-l+1));
                while(sum>=target && l<=r){
                    ans = min(ans,(r-l+1));
                    sum = sum-nums[l];
                    l++;
                }
                r++;
            }
            else{
                r++;
            }

        }

        return ans;
    }
};
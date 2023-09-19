class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);

        for(int i=n-1; i>=0; i--){
            int cnt=1;
            for(int j=i+1; j<n; j++){
                if(nums[j]>nums[i]){
                    ans[i]=max(ans[j]+1,ans[i]);
                }
            }
        }

        int res=0;
        for(int i=0; i<n; i++){
            res = max(res, ans[i]);
        }

        return res;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=1;
        }

        int prefix_pd=1;
        for(int i=0; i<n-1; i++){
            prefix_pd *= nums[i];
            ans[i+1] *= prefix_pd;
        }

        int postfix_pd=1;
        for(int i=n-1; i>0; i--){
            postfix_pd  *= nums[i];
            ans[i-1] *= postfix_pd;
        }

        return ans;
    }
};
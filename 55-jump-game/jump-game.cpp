class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int target = n-1;
        if(n==1) return true;
        if(nums[0]==0) return false;
        

        vector<int>ans(n);
        for(int i=0; i<n;i++){
            ans[i]=0;
        }

        for(int i=0; i<n-1; i++){
            int j=nums[i];
            int k=i+1;
            while(j>0 && k<n){
                ans[k]++;
                j--;
                k++;
            }
        }

        for(int i=1; i<n; i++){
            if(ans[i]==0)return false;
        }

        return true;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        
        int ans=0;

        int prev=-1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                prev=i;
                break;
            }
        }
        ans= prev;
        for(int i=prev+1; i<n; i++){
            if(nums[i]==0){
                ans = max(ans, i-prev-1);
                prev=i;
            }
        }
        if(prev==-1) return n;

        ans = max(ans, n-1-prev);

        return ans;
    }
};
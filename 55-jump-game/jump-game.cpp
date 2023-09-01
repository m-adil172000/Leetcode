class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int target = n-1;
        if(n==1) return true;
        if(nums[0]==0) return false;
        

        for(int i=n-1; i>0; i--){
                if(nums[i-1]+(i-1)>=target){
                        target = i-1;
                }
        }
        
            if(target == 0){
                    return true;
            }
            else return false;
            
    }
};
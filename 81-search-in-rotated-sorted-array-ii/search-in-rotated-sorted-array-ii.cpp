class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n = nums.size();

       int l=0, r=n-1;
       while(l<=r){
           int m = l + (r-l)/2;

           if(nums[m]==target) return true;
           
           // we are in left portion of the array
           if(nums[l]<nums[m]){
               // if the target is in the left portion of the array
               if(nums[m]>target && nums[l]<=target){
                   r = m -1;
               }
               else l = m+1;
           }
           // we are in right portion of the array
           else if(nums[l]>nums[m]){
               // if the target is in the right portion of the array
               if(nums[m]<target && nums[r]>=target){
                   l = m+1;
               }
               else r =m-1;
           }
           // here we can do binary search so we just increase our left pointer
           else l++;
       } 
       return false;
    }
};
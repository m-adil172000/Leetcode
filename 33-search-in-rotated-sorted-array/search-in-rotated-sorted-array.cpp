class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                // if we are in left sorted portion of array
                if(nums[mid]>=nums[l]){
                    if(nums[l]<=target){
                        r = mid -1;
                    }
                    else l = mid+1;
                }
                // if we are in right sorted portion of array
                else{
                    r = mid -1;
                }
            }
            else{
                // if we are in left sorted portion of array
                if(nums[mid]>=nums[l]){
                    l = mid + 1;
                }
                // if we are in right sorted portion of array
                else{
                    if(nums[r]>=target){
                        l = mid+1;
                    }
                    else r = mid-1;
                }
            }
        }

        return -1;
    }
};
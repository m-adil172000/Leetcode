class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n =nums.size();
        if(n==1) return 0;
        if(nums[1]<nums[0]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int s = 1, e = n-2;

        int mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                s = mid+1;
            }
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]){
                e = mid-1;
            }
            else{
                s = mid + 1;
                // or e = mid - 1;
            }
        }

        return -1;
    }
};
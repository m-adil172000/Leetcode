class Solution {
public:
    void sortColors(vector<int>& nums) {

        /*
        This problem is a variation of the popular Dutch National flag algorithm
        This algorithm contains 3 pointers. Three rules
        arr[0….low-1] contains 0. [Extreme left part]
        arr[low….mid-1] contains 1.
        arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array

        Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as
         they represent the unsorted part in the hypothetical array.
        
        */

        int n=nums.size();
        int low=0,mid=0,high=n-1;

        while(mid <= high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
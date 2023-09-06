class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        //We need to find how many times, the array is breaking the ascending order. If it is breaking just once then it or it
        // does't break even once then it is sorted. So we can return true. Otherwise false.
        int brk=0;
        for(int i=1; i<n; i++){
            if(nums[i-1]>nums[i]){
                brk++;
            }
        }
        if(nums[n-1]>nums[0]) brk++;

        return brk<=1;
    }
};
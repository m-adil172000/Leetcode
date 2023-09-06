class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();
        
        int elem = n+1;
        int target = elem*(elem-1)/2;
        int sum=0;

        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        return target-sum;
    }
};
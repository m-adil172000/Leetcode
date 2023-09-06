class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
    // Kadane's Algorithm
    /*
    The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
    */

    int n = nums.size();
    if(n==1) return nums[0];

    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
   
    return maxi;

    }
    
};
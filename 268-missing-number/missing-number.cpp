class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        Assume the given array is: {1, 2, 4, 5} and N = 5.
        XOR of (1 to 5) i.e. xor1 = (1^2^3^4^5)
        XOR of array elements i.e. xor2 = (1^2^4^5)
        XOR of xor1 and xor2 = (1^2^3^4^5) ^ (1^2^4^5)
			= (1^1)^(2^2)^(3)^(4^4)^(5^5)
			= 0^0^3^0^0 = 0^3 = 3.
        The missing number is 3.
        */

        int n = nums.size();
        int xor1=0,xor2=0;

        for(int i=0; i<n; i++){
            xor1 ^= (i);
            xor2 ^= nums[i];
        }
        xor1 ^= n; // to include n in the XOR

        return xor1^xor2;
        
    }
};


/*
SUM Approach

int n=nums.size();
        
int elem = n+1;
int target = elem*(elem-1)/2;
int sum=0;

for(int i=0; i<n; i++){
    sum += nums[i];
}
return target-sum;
*/

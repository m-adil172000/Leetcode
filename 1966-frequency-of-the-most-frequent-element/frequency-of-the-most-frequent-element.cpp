class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        // first of all we need to sort the array because we can only increase the elements so we need smaller elements on the left
        // and the closest value will be incremented first
        sort(nums.begin(), nums.end());

        // Now we apply sliding window
        long long l=0; // our left and right iterators
        long long r=0;

        long long total=0; //the actual sum of the window
        long long ans=0; // the final answer

        while(r < n){
            total += nums[r]; //to get the total sum of our current window;
            // (r-l+1)-> length of our current window

            // Now we check if the sum of the window (if all elements in the window are changes to nums[r]) is less than what we can make
            // by adding k to the elements
            // if yes then then we expand our window else we contract it by increasing the left pointer
            while(nums[r]*(r-l+1) > total + k){
                total = total - nums[l]; // removing the left pointer value from the sum of that window length
                l++;  // contracting the window
            }

            //now we update our answer with the length because the maximum allowed window length will be our answer
            ans = max(ans,(r-l+1));
            r++;
        }

        return ans;

    }
};
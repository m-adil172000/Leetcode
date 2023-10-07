class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;

        // we are going to transform our array--- if the element is odd then change is to 1 else change is to 0
        // Now to find number of subarrays with k odd numbers, the transformed question becomes-- find the number of subarrays with sum k
        // bcz only odd numbers i.e. 1 will contribute to sum.

        //To find number of subarrays with sum equal to k is a standard problem.

        for(int i=0; i<n; i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }

        unordered_map<int,int>mp; //to store the count of prefix sum
        int pref_sum=0;

        for(int i=0; i<n; i++){
            pref_sum += nums[i];
            if(pref_sum==k) ans++;

            if(mp.find(pref_sum-k) != mp.end()){
                ans += mp[pref_sum-k];
            }

            mp[pref_sum]++;

        }

        return ans;
    }
};
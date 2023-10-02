class Solution {
private:
    long long sum(int d, vector<int>nums){
        long long ans=0;

        for(int i=0; i<nums.size(); i++){
            ans += ceil((double)nums[i]/(double)d);
        }

        return ans;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int l = 1;
        int r = INT_MIN;
        for(auto it:nums){
            r = max(r,it);
        }
        int ans=0;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(sum(mid,nums)<=threshold){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;

    }
};
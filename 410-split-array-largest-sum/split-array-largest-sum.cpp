class Solution {
private:
    int partition(vector<int>nums, int lim){
        int ans=1;
        long long curr=0;

        for(int i=0; i<nums.size(); i++){
            if(curr + nums[i] <= lim){
                curr += nums[i];
            }
            else{
                curr = nums[i];
                ans++;
            }
        }

        return ans;
    }    
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int l = INT_MIN, r=0;
        for(int i=0; i<n; i++){
            l=max(l, nums[i]);
            r += nums[i];
        }
        int ans=0;
        while(l<=r){
            int m = l+(r-l)/2;
            int cnt = partition(nums,m);
            if(cnt<=k){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }

        return ans;
    }
};
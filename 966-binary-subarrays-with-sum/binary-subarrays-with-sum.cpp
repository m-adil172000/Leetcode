class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n =nums.size();
        int prefSum=0;
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0; i<n; i++){
            prefSum += nums[i];
            if(prefSum==goal){
                ans++;
            }

            if(mp[prefSum-goal]>0){
                ans += mp[prefSum-goal];
            }
            mp[prefSum]++;
        }

        return ans;
    }
};
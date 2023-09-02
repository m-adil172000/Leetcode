class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>order, rev;
        int n=nums.size();
        int s=1,e=1;
        for(int i=0;i<n; i++){
            s = s*nums[i];
            e = e*nums[n-1-i];
            order.push_back(s);
            rev.push_back(e);
        }

        vector<int>ans;
        int val=1;
        ans.push_back(rev[n-2]);
        for(int i=1; i<n-1; i++){
            val = order[i-1]*rev[n-2-i];
            ans.push_back(val);
        }
        ans.push_back(order[n-2]);

        return ans;
    }
};
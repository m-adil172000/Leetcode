class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target)-nums.begin();

        int n=nums.size();
        if(n==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        if(lb != n){
            if(nums[lb]==target){
                ans.push_back(lb);
            }
            else ans.push_back(-1);
        }
        else ans.push_back(-1);

        if(ub-1 >0){
            if(nums[ub-1]==target){
                ans.push_back(ub-1);
            }
            else ans.push_back(-1);
        }
        else if(ub-1==lb){
            ans.push_back(lb);
        }
        else ans.push_back(-1);
        
        return ans;


    }
};
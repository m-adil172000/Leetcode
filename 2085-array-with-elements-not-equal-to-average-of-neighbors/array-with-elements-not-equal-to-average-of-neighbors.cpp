class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>ans;

        int i=0,j=n-1;
        while(i<=j){
            if(i!=j){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
            }
            else ans.push_back(nums[i]);

            i++;
            j--;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocnt=0;
        int pd=1;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zerocnt++;
            }
            else{
                pd = pd*nums[i];
            }
        }

        vector<int>ans;

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(zerocnt==1){
                    ans.push_back(pd);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                if(zerocnt>=1){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(pd/(nums[i]));
                }
            }
        }

        return ans;
    }
};
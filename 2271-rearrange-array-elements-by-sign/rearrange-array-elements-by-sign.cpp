class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        vector<int>pos;
        vector<int>neg;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                pos.push_back(i);
            }
            else neg.push_back(i);
        }
        

        int i=0,j=0;
        while(j<neg.size()){
            ans.push_back(nums[pos[j]]);
            ans.push_back(nums[neg[j]]);
            j++;
        }

        return ans;
    }
};
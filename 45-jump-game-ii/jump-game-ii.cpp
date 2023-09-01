class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int steps=0;

        int target=n-1;
        vector<int>ans(n-1);
        for(int i=0; i<n-1; i++){
            ans[i]=i+nums[i];
        }
        
        while(target != 0){
            for(int i=0; i<ans.size(); i++){
                if(ans[i]>=target){
                    target=i;
                    steps++;
                    break;
                    
                }
            }
        }

        return steps;

    }
};
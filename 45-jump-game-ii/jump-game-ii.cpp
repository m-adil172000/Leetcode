class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int steps=0;

        int left=0, right=0;
            
            while(right<n-1){
                    int farthest=0;
                    for(int i=left; i<=right; i++){
                            farthest= max(farthest, i+nums[i]);
                    }
                    left = right+1;
                    right = farthest;
                    steps++;
            }
            
            return steps;

    }
};
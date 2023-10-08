class Solution {
public:
    int solve(vector<int>&nums, int goal){
        if(goal<0) return 0;

        int s=0,sum=0;
        int ans=0;

        for(int e=0;e<nums.size(); e++){
            sum += nums[e];

            while(sum>goal){
                sum -=nums[s];
                s++;
            }
            ans += e-s+1;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n =nums.size();
        
        int atmost_goal = solve(nums,goal);
        int atmost_goalMinusOne = solve(nums,goal-1);

        return atmost_goal - atmost_goalMinusOne;
        
    }
};
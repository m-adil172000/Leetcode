class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>curr, int sum, int s){
        if(sum==target){
            
            ans.push_back(curr);
            return;
        }
        else if(sum>target){
            return;
        }

        for(int i=0; i<candidates.size(); i++){
            if(i<s) continue;
            curr.push_back(candidates[i]);
            s=i;
            sum += curr.back();
            solve(candidates,target,ans,curr,sum, s);
            sum -= curr.back();
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>curr;
        int sum=0;
        solve(candidates, target, ans, curr, sum,0);

        return ans;
    }
};
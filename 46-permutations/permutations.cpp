class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>curr, int n, unordered_map<int,bool>visited){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++){
            if(visited[nums[i]]){
                continue;
            }
            else visited[nums[i]]=true;
            curr.push_back(nums[i]);
            solve(nums, ans, curr, n, visited);
            curr.pop_back();
            visited[nums[i]]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>ans;
        vector<int>curr;
        unordered_map<int,bool>visited;
        solve(nums,ans,curr,n, visited);

        return ans;
    }
};
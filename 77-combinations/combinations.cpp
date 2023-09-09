class Solution {
public:

    void solve(int k, int n, vector<vector<int>>&ans, vector<int>curr, int s){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        
        

        for(int i=s; i<=n; i++){
            
            curr.push_back(i);
            solve(k,n,ans,curr,i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        
        vector<int>curr;

        solve(k,n,ans,curr,1);

        return ans;
    }
};
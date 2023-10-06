class Solution {
private:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>&dp){
        if(i==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MAX;
        for(int k=0; k<m; k++){
            int curr = grid[i][j] + moveCost[grid[i][j]][k] + solve(i+1,k,n,m,grid,moveCost,dp);
            ans = min(curr,ans);
        }

        return dp[i][j] = ans;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        // we can move from any valid cell of ith row to any other valid cell of (i+1)th row
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0; j<m; j++){
            ans = min(ans,solve(0,j,n,m,grid,moveCost,dp));
        }

        return ans;
    }
};
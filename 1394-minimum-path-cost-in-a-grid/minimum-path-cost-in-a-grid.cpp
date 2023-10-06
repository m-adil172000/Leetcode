class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        // we can move from any valid cell of ith row to any other valid cell of (i+1)th row
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int j=0; j<m; j++) dp[n-1][j]=grid[n-1][j];

        for(int i = n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                int temp=INT_MAX;
                for(int k=0; k<m; k++){
                    temp = min(temp,grid[i][j] + moveCost[grid[i][j]][k] + dp[i+1][k]);
                }
                dp[i][j]=temp;
                
            }
        }

       
        int ans=INT_MAX;
        for(int i=0; i<m; i++){
            ans= min(ans,dp[0][i]);
        }

        return ans;
    }
};
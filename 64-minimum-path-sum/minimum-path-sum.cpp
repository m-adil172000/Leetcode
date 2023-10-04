class Solution {

public:
   
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m,0));
        dp[0][0] = grid[0][0];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) continue;
                long long left =grid[i][j], up=grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up = INT_MAX;
                if(j>0) left += dp[i][j-1];
                else left = INT_MAX;

                dp[i][j] = min(up,left);
            }
        }

        return dp[n-1][m-1];
    }
};
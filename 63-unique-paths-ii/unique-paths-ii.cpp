class Solution {
private:
    int grid(vector<vector<int>>& obstacleGrid,int i, int j, vector<vector<int>>&dp){

        if(i==0 && j==0 && obstacleGrid[i][j]!=1){
            return 1;
        }
        if(i<0 || j<0 || obstacleGrid[i][j]==1){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int left = grid(obstacleGrid, i, j-1, dp);
        int up = grid(obstacleGrid, i-1, j, dp);

        return dp[i][j] = left+up;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n, vector<int>(m,-1));

        return grid(obstacleGrid,n-1,m-1,dp);
    }
};
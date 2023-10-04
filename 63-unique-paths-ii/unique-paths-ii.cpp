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

        vector<vector<int>>dp(n, vector<int>(m,0));
        if(obstacleGrid[0][0]==1){
            dp[0][0]=0;
        }
        else dp[0][0]=1;

        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){

                if(i==0 && j==0) continue;

                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    int left = 0, up=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[n-1][m-1];
    }
};
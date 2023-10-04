class Solution {
private:
    int path(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(i==n-1){
            return triangle[n-1][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        long long down=INT_MAX, diagonal = INT_MAX;

        down = triangle[i][j]+path(i+1,j,n,triangle,dp);
        diagonal = triangle[i][j] + path(i+1,j+1,n,triangle,dp);

        return dp[i][j] = min(down,diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(triangle[n-1].size(),-1));

        return path(0,0,n, triangle, dp);
    }
};
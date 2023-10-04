class Solution {
private:
    long long solve(int i, int j, int n, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(i>n-1 || j>n-1 || i<0 || j<0) return INT_MAX;
        if(i==n-1){
            return matrix[n-1][j];
        }


        if(dp[i][j] != INT_MAX) return dp[i][j];

        long long ld=INT_MAX, rd=INT_MAX, down = INT_MAX;
        ld =matrix[i][j] +  solve(i+1,j-1,n,matrix,dp);
        rd =matrix[i][j] +  solve(i+1,j+1,n,matrix,dp);
        down = matrix[i][j] + solve(i+1,j,n,matrix,dp);

        return dp[i][j] = min(down, min(ld,rd));
    }   
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(n,INT_MAX));
        long long ans=INT_MAX;

        for(int j=0; j<n; j++){
            ans = min(ans,solve(0,j,n,matrix,dp));
        }

        return ans;

    }
};
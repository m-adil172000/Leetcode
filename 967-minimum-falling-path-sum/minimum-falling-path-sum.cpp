class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j=0; j<m; j++) dp[0][j] = matrix[0][j];

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int ld=INT_MAX,rd=INT_MAX;
                if(j-1>=0) ld = matrix[i][j] + dp[i-1][j-1];
                int d = matrix[i][j] + dp[i-1][j];
                if(j+1<m) rd = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(d, min(ld,rd));
            }
        }

        int ans=INT_MAX;
        for(int j=0; j<m; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
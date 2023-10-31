// we do index shifting to one right to perform tabulation. So, the n means n-1 , 1 means 0, and 0 means -1.
class Solution {
private:
    int LCS(int i, int j,string&s1, string &s2, vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //if the character at the ith index in string1 match with the character at the jth index in string2
        if(s1[i] == s2[j]) return dp[i][j] = 1 + LCS(i-1,j-1,s1,s2,dp);

        //if they don't match then either the s1[i-1] will match with s2[j] OR s1[i] will match with s2[j-1]. we need to take max from both.
        return dp[i][j] = max(LCS(i-1,j,s1,s2,dp) , LCS(i,j-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0; i<=n; i++){
           dp[i][0]=0;
        }
        for(int j=0; j<=m; j++){
            dp[0][j]=0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[n][m];

    }
};
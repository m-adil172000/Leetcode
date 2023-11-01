// I tried it with pointing one index to start of the string and one to the end of it. Applied DP usng this method.
/*
int solve(int i, int j, string &s, vector<vector<int>>&dp){

        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j] =  2 + solve(i+1,j-1,s,dp);
        }
        return dp[i][j] = max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
    }
*/

//Instead we can solve this by using Longest Common Subsequence approach. We can make another string which is reverse of the original string and if we find the LCS of both then that will be also the longest Palindromic subsequence.
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=0; i<n; i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
        
    }
};
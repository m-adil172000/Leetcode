class Solution {
private:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){

        if(j<0) return i+1;
        if(i<0) return j+1;

        if(dp[i][j] != -1) return dp[i][j];
        

        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        }
        else{
            //int insert =1 + min(solve(i,j-1,s1,s2),solve(i-1,j,s1,s2));
            //int replace =1 + solve(i-1,j-1,s1,s2);
            //int del = 1 +  min(solve(i-1,j,s1,s2), solve(i,j-1,s1,s2));

            return dp[i][j] =  1+ min({solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp),solve(i-1,j-1,s1,s2,dp)});
        }

    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,word1,word2,dp);
    }
};
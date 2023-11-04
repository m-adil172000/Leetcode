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
        if(n==0 || m==0) return max(n,m);
        vector<int>prev(m+1,0), curr(m+1,0);
        for(int j=0; j<=m; j++) prev[j] =j;

        for(int i=1; i<=n; i++){
            curr[0]=i;   //very important to not forget this
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                }
            }
            prev = curr;
        }

        return prev[m];

    }
};
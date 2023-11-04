class Solution {
private:
    bool allstars(int i, string &p){
        
        for (int j = 0; j <= i; j++) {
            if (p[j] != '*')
                return false;
        }
        return true;
    }
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>&dp){

        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false; 
        if(i<0 && j>=0) return allstars(j,p);

        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] =  solve(i-1,j-1,s,p,dp);
        }
        else{
            if(p[j]=='*'){
                return dp[i][j] = solve(i,j-1,s,p,dp) || solve(i-1,j,s,p,dp);
            }
            else return false;
        }
    }
public:
    bool isMatch(string s, string p) {
       int n = s.length();
       int m = p.length();

       vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
       if(s.length()>0 && p.length()==0) return false;
       if (allstars(m-1,p)) return true;

       dp[0][0]=true;
       for(int i=1; i<=n; i++) dp[i][0]=false;
       for(int j=1; j<=m; j++) dp[0][j] = allstars(j-1,p);

       for(int i=1; i<=n; i++){
           for(int j=1; j<=m; j++){
               if(s[i-1]==p[j-1] || p[j-1]=='?'){
                   dp[i][j] = dp[i-1][j-1];
               }
               else{
                   if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                   else dp[i][j] = false;
               }
           }
       }

       return dp[n][m];
       
    }
};
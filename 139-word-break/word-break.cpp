class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        vector<int>dp(n+1,false);
        dp[n]=true;

        unordered_map<string,bool>mp;
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]=true;
        }

        for(int i=n-1; i>=0; i--){
            for(auto it:mp){
                if(i+(it.first.length()) <= n && s.substr(i,it.first.length())==it.first){
                    dp[i] = dp[i+it.first.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }

        return dp[0];
    }
};
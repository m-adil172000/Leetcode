class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        unordered_map<char,bool>mp;
        if(n==0) return 0;
        int l=0,r=1;
        int ans=1;
        mp[s[0]]=true;

        while(r<n){
            
            if(mp[s[r]]==false){
                ans = max(ans, r-l+1);
                mp[s[r]]=true;
                r++;
            }
            else{
                char c=s[r];
                while(s[l]!=c && l<r){
                    mp[s[l]]=false;
                    l++;
                }
                if(l<r) l++;
                mp[s[l]]=true;
                r++;
            }
            
        }

        return ans;
    }
};
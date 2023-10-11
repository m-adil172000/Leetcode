class Solution {
public:
    int maxfreq(unordered_map<char,int>&cnt){
        int ans = 0;
        for(auto it: cnt){
            ans = max(ans, it.second);
        }

        return ans;
    }
    int characterReplacement(string str, int k) {
        int s=0,e=0, n=str.length();
        unordered_map<char,int>cnt;
        int res=0;

        while(e<n){
            cnt[str[e]]++;

            while((e-s+1)-maxfreq(cnt) >k){
                cnt[str[s]]--;
                s++;
            }

            res = max(res,e-s+1);
            e++;
        }

        return res;
    }
};
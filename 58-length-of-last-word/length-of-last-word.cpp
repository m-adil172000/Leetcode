class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int ans=0;

        bool found=false;
        for(int i=n-1; i>=0; i--){
            if(s[i]==' '&& found) break;
            if(s[i]!=' '){
                found=true;
                ans++;
            }
        }

        return ans;
    }
};
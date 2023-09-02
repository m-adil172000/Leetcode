class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int ans=0;

        int i=n-1;
        while(s[i]==' ') i--;

        while(s[i] != ' '){
            ans++;
            i--;
            if(i<0) break;
        }

        return ans;
    }
};
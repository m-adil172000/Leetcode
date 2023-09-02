class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();

        if(m>n){
            return -1;
        }

        int i=0,j=0;
        int ans=-1;
        for(int i=0; i<n; i++){
            if(haystack[i]==needle[j]){
                ans = i;
                int f=i, c=j;
                while(haystack[f]==needle[c] && c<m){
                    f++;
                    c++;
                }
                if(c==m){
                    return i;
                }
                else ans=-1;
            }
        }

        return ans;
    }
};
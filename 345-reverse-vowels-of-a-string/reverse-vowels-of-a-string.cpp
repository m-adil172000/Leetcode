class Solution {
public:
    string reverseVowels(string s) {
        stack<char>vow;
        int n =s.length();
        for(auto it:s){
            if(it=='a' ||it=='e' ||it=='i' ||it=='o' ||it=='u' || it=='A' ||it=='E' ||it=='I' ||it=='O' ||it=='U'){
                vow.push(it);
            }
        }

        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' || s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U'){
                ans+=vow.top();
                vow.pop();
            }
            else ans+=s[i];
        }

        return ans;
        
    }
};
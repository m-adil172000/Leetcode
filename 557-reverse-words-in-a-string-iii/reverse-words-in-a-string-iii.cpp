class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ')st.push(s[i]);
            else{
                while(st.size()>0){
                    ans += st.top();
                    st.pop();
                }
                ans+=" ";
            }
        }
        while(st.size()>0){
                    ans += st.top();
                    st.pop();
                }
        
        

        return ans;
    }
};
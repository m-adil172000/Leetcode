class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();

        stack<pair<char,int>>st;

        for(int i=0; i<n; i++){
            if(st.size()>0 && st.top().first==s[i]){
                st.top().second ++;
            }
            else{
                st.push({s[i],1});
            }

            if(st.top().second == k){
                st.pop();
            }
        }

        string ans="";
        while(st.size()>0){
            for(int i=0; i<st.top().second; i++) ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
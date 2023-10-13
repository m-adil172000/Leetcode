class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();

        unordered_map<char,int>cnt;
        for(int i=0; i<n; i++) cnt[s[i]]++;

        unordered_map<char,bool>visited;
        for(int i=0; i<n; i++) visited[s[i]]=false;

        stack<char>st;
        string ans="";

        for(int i=0; i<n; i++){
            if(visited[s[i]]){
                cnt[s[i]]--;
                continue;
            }
            while(st.size()>0 && (st.top()>s[i] )&& cnt[st.top()]>0){
                visited[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]]=true;
            cnt[s[i]]--;
        }

        while(st.size()>0){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};
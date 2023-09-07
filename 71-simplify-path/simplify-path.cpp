class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        path += '/';
        int n=path.length();
        string ans="";

        string curr="";

        for(int i=0; i<n; i++){
            if(path[i]=='/'){
                if(curr==".."){
                    if(st.size() >0){
                        st.pop();
                    }
                }
                else if(curr != "" && curr != "."){
                    st.push(curr);
                }

                curr= "";
            }
            else{
                curr += path[i];
            }
        }
        stack<string>rev;
        while(st.size() != 0){
            rev.push(st.top());
            st.pop();
        }

        if(rev.size()==0){
            ans += '/';
            return ans;
        }

        while(rev.size() >0){
            ans += '/';
            ans += rev.top();
            rev.pop();
        }
        return ans;
    }
};
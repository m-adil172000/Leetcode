class Solution {
public:

    void solve(vector<string>&ans, string curr, int co, int cc, int n){

        /*
        we can add open para if open count is less than n
        we can add close para if close count is less than n bcz closed para can't be our starting para
        if both count==n, we save to answer and return
        */
        if(co==n && cc == n){
            ans.push_back(curr);
            return;
        }

        if(co<n){
            curr += '(';
            solve(ans, curr, co+1, cc, n);
            curr.pop_back();
        }
        if(cc < co){
            curr += ')';
            solve(ans, curr, co, cc+1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";

        int co=0,cc=0;

        solve(ans, curr, co, cc, n);

        return ans;



    }
};
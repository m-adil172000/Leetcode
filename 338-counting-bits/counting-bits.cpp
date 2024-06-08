class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        int offset=1;

        for(int i=1; i<=n; i++){
            if(offset*2==i){
                offset=i;
            }
            dp[i] = 1 + dp[i-offset];
        }

        return dp;
    }
};














/*
vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        int offset=1;

        for(int i=1; i<=n; i++){
            if(offset*2 == i){
                offset = i;
            }

            dp[i] = 1 + dp[i-offset];
        }

        return dp;
    }
*/

/*
this is also O(n) solution , by me

vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        ans[0]=0;
        if(n==0){
            return ans;
        }
        ans[1]=1;
        if(n==1){
            return ans;
        }
        ans[2]=1;
        if(n==2){
            return ans;
        }
        for(int i=3; i<=n; i++){
            if(i%2==0){
                ans[i] = ans[i/2];
            }
            else ans[i] = ans[i/2]+1;
        }

        return ans;
    }

*/
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int rs = startPos[0], cs = startPos[1];
        int re = homePos[0], ce = homePos[1];
        int n = rowCosts.size(), m = colCosts.size();
        int ans=0;

        if(rs<=re){
            for(int i=rs+1; i<=re; i++) ans += rowCosts[i];
        }
        else{
            for(int i = rs-1; i>=re; i--) ans += rowCosts[i];
        }

        if(cs<=ce){
            for(int i=cs+1; i<=ce; i++) ans += colCosts[i];
        }
        else{
            for(int i = cs-1; i>=ce; i--) ans += colCosts[i];
        }
        

        return ans;
    }
};
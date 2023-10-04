class Solution {

public:
   
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>prev(m,0);

        for(int i=0; i<n; i++){
            vector<int>curr(m,0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    curr[j] = grid[0][0];
                    continue;
                }
                long long left =grid[i][j], up=grid[i][j];
                if(i>0) up += prev[j];
                else up = INT_MAX;
                if(j>0) left += curr[j-1];
                else left = INT_MAX;

                curr[j] = min(up,left);
            }

            prev = curr;
        }

        return prev[m-1];
    }
};
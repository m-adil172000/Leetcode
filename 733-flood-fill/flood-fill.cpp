class Solution {
public:

    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color,int initcol, int drow[], int dcol[]){
        ans[sr][sc] = color;
        int n = ans.size();
        int m = ans[0].size();

        
        for(int i=0; i<4; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initcol && ans[nrow][ncol] != color){
                dfs(image,ans, nrow, ncol, color, initcol, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans = image;
        int initcol = image[sr][sc];

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        dfs(image, ans, sr, sc, color, initcol, drow, dcol);

        return ans;
    }
};
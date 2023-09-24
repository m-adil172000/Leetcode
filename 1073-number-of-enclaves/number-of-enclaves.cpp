class Solution {
private:

/*
    void dfs(int sr, int sc, int drow[], int dcol[], vector<vector<int>>&visited, vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        visited[sr][sc]=1;

        for(int i=0; i<4; i++){
            int nr = sr + drow[i];
            int nc = sc + dcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,drow, dcol, visited, grid);
            }
        }
    }
*/
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }

        while(q.size()>0){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc] && grid[nr][nc]==1){
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
        }

        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }

        return ans;

        
    }
};
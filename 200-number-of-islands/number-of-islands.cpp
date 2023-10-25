class Solution {
public:

    void bfs(vector<vector<char>>& grid, int n, int m, int sx, int sy,vector<vector<int>>& visited ){
        visited[sx][sy]=1;
        queue<pair<int,int>>q;
        q.push({sx, sy});

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        while(q.size() != 0){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = cx + drow[i];
                int ncol = cy + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    q.push({nrow, ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m =grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    bfs(grid, n, m, i, j, visited);
                    ans++;
                }
            }
        }

        return ans;

    }
};
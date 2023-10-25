class Solution {
private:
    void bfs(int x, int y, int&curr, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[x][y]=true;
        curr++;
        int n = grid.size();
        int m = grid[0].size();

        int drow[4] = {-1,0,+1,0};
        int dcol[4] = {0,+1,0,-1};
        queue<pair<int,int>>q;
        q.push({x,y});

        while(q.size()>0){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !visited[nr][nc]){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                    curr++;
                }
            }
        } 
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curr=0;

                if(!visited[i][j] && grid[i][j]==1){
                    bfs(i,j,curr,grid,visited);
                    ans = max(ans,curr);
                }
            }
        }

        return ans;
    }
};
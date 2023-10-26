class Solution {
private:
    int bfs(int x, int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>&visited){
        int n = grid1.size();
        int m = grid1[0].size();

        int drow[4] = {-1,0,+1,0};
        int dcol[4] = {0,+1,0,-1};

        queue<pair<int,int>>q;
        visited[x][y]=true;
        q.push({x,y});
        bool status=true;
        if(grid1[x][y]==0) status=false;

        while(q.size()>0){
            auto it= q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid2[nr][nc]==1 && !visited[nr][nc]){
                    if(grid1[nr][nc]==0){
                        status=false;
                    }
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }

        if(status) return 1;
        else return 0;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]==1 && !visited[i][j]){
                    ans += bfs(i,j,grid1,grid2,visited);
                }
            }
        }

        return ans;
    }
};
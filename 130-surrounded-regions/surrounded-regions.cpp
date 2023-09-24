class Solution {

private:
    void dfs(int sr, int sc, vector<vector<int>> &visited, vector<vector<char>> &board, int drow[], int dcol[]) {
        visited[sr][sc] = 1; 
        int n = board.size();
        int m = board[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board, drow, dcol); 
            }
        }
    }
    /*
    void bfs(vector<vector<char>>&board, vector<vector<int>>&visited, int sr, int sc, int n, int m, int drow[], int dcol[]){

        
        queue<pair<int,int>>q;
        q.push({sr,sc});

        while(q.size()>0){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            visited[r][c]=1;

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc >=0 && nc<m && !visited[nr][nc] && board[nr][nc]=='O'){
                    q.push({nr,nc});
                }
            }
        }

    }
    */

public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        for(int j=0; j<m; j++){
            if(visited[0][j]==0 && board[0][j]=='O'){
                dfs(0, j, visited, board, drow, dcol);
            }
            if(visited[n-1][j]==0 && board[n-1][j]=='O'){
                dfs(n-1, j, visited, board, drow, dcol);
            }
        }
        
        for(int i=0; i<n; i++){
            if(visited[i][0]==0 && board[i][0]=='O'){
                 dfs(i, 0, visited, board, drow, dcol);
            }
            if(visited[i][m-1]==0 && board[i][m-1]=='O'){
                 dfs(i, m-1, visited, board, drow, dcol);
            }
        }
    

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }



    }
};
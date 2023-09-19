class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }

        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};

        while(q.size()>0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            ans[r][c]=d;

            for(int i=0; i<4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];

                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col]){
                    visited[row][col]=1;
                    q.push({{row,col},d+1});
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int time=0, fresh=0;
        queue<pair<int,int>>q; //it will store the location of rotten oranges

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        //The neighbours of an orange
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};

        //while(all the fresh oranges are not rotten && q.size()>0)
        while(q.size() > 0  && fresh>0){

            int l = q.size();
            // select all rotten oranges and make their neighbours rotten in the same unit of time
            for(int i=0; i<l; i++){

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j=0; j<4; j++){
                    int row = r + drow[j];
                    int col = c + dcol[j];

                    if(row<0 || row==n || col<0 || col==m || grid[row][col] != 1) continue;
                    grid[row][col]=2;
                    q.push({row,col});
                    fresh--;
                }
            }
            time++;
        }

        if(fresh >0 ) return -1;
        else return time;
    }
};
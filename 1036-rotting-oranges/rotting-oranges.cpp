class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q; // here we will stor {{row,column}, time}
        int visited[n][m];
        int cntfresh=0; // to keep track if all the fresh oranges were rotten or not

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    //if the orange is rotten then we will add it to the queue and mark it visited. And initial time in all of them will be 0
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }

                if(grid[i][j]==1) cntfresh++;
            }
        }

        int time=0; // final answer

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};  // to get the neighbours of the current element
        int cnt=0; //to match with cntfresh

        while(q.size() != 0){
            int cr = q.front().first.first; // get the current row
            int cc = q.front().first.second; // get the current column
            int t = q.front().second; //get the current time
            time = max(time,t); // upadate the answer
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = cr + drow[i];  //get the neighbour row
                int ncol = cc + dcol[i];  //get the neighbour column


                //check for valid cell and then for unvisited orange and if that is a fresh orange
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1}); //push it in queue with increased timer
                    visited[nrow][ncol]=2;  // mark as rotten
                    cnt++;   // to match if all fresh oranges are rotten or not
                }
            }
        }

        if(cnt != cntfresh) return -1;

        return time;

        
        

    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // we will solve this using Dijsktra Algorithm
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;  //bcz we need the length of the path

        queue<pair<int,pair<int,int>>>q;  // bcz all distances to the adjacent nodes are at +1, so the queue itself will store elements in ascending order
        q.push({1,{0,0}});

        int drow[]={-1,-1,-1,0,+1,+1,+1,0};  // to move to adjacent elements
        int dcol[]={-1,0,+1,+1,+1,0,-1,-1};

        while(q.size()>0){
            auto it=q.front();
            int r=it.second.first;
            int c=it.second.second;
            int d=it.first;
            q.pop();

            for(int i=0; i<8; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    if(d + 1 < dist[nr][nc]){
                        dist[nr][nc]=d+1;
                        if(nr==n-1 && nc==n-1) return dist[nr][nc];  //if we have reached the destination then we simply return bcz as all other distances will lead to greater than the current found
                        q.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }

        }
        if(dist[n-1][n-1]!=INT_MAX) return dist[n-1][n-1];
        return -1;
        
        
    }
};
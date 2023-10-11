class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }

        for(int i=0; i<n; i++) matrix[i][i]=0;

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][k]==1e9 || matrix[k][j]==1e9) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
            }
        }

        int city=-1,cnt=0,cntmx=n+1;

        for(int i=0; i<n; i++){
            cnt=0;
            for(int j=0; j<n; j++){
                if(matrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<cntmx){
                cntmx = cnt;
                city = i;
            }
            else if(cnt==cntmx) city=i;
        }

        return city;
    }
};


/*
In order to solve this problem, we will use the Floyd Warshall algorithm (article link of Floyd Warshall). We know Floyd Warshall algorithm helps us to generate a 2D matrix, that stores the shortest distances from each node to every other node. In the generated 2D matrix, each cell matrix[i][j] represents the shortest distance from node i to node j.

After generating the 2D matrix(that contains the shortest paths) using the Floyd Warshall algorithm, for each node, we will count the number of nodes with a distance lesser or equal to the distanceThreshold by iterating each row of that matrix. Finally, we will choose the node with the minimum number of adjacent cities(whose distance is at the most distanceThreshold) and with the largest value.
*/
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
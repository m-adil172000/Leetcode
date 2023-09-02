class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, int n, int sv, bool*visited){
        visited[sv]=true;
        for(int i=0; i<n; i++){
            if(i==sv || visited[i]) continue;
            if(isConnected[sv][i]==1){
                dfs(isConnected, n, i, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        bool*visited = new bool[n];
        for(int i=0; i<n; i++) visited[i]=false;

        int province=0;

        for(int i=0; i<n; i++){
            if(visited[i]==false){
                dfs(isConnected, n, i, visited);
                province++;
            }
        }

        return province;
        
    }
};
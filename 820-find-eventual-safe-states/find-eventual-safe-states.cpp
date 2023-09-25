class Solution {

private:
    bool dfs(int s, vector<vector<int>>&graph, vector<int>&visited, vector<int>&pathvisited, vector<int>&check){
        visited[s]=1;
        pathvisited[s]=1;

        check[s]=0;

        for(auto it: graph[s]){
            if(!visited[it]){
                if(dfs(it, graph, visited, pathvisited, check)==true){
                    check[s]=0;
                    return true;
                }
            }
            else if(pathvisited[it]){
                check[s]=0;
                return true;
            }
        }

        check[s]=1;
        pathvisited[s]=0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>pathvisited(n,0);
        vector<int>check(n,0);
        vector<int>safenodes;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, graph, visited, pathvisited, check);
            }
        }

        for(int i=0; i<n; i++){
            if(check[i]){
                safenodes.push_back(i);
            }
        }

        return safenodes;

    }
};
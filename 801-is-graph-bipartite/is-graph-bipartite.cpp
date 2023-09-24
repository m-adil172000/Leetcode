class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();

        vector<int>color(n,-1); // to store which vertices are colored
        queue<int>q; // to store the vertex
        
        for(int i=0; i<n; i++){
            if(color[i]==1) continue;
            else{
                color[i]=0;
                q.push(i);
            }
        while(q.size()>0){
            int node = q.front();
            q.pop();

            for(auto it:graph[node]){
                // if the adjacent node is not colored yet, then we give it the opposite color
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // if the adjacent node has the same color as the current node
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        }
        

        return true;
        
    }
};
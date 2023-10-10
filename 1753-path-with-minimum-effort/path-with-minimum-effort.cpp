class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int eff = it.first;

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neweffort = max(eff, abs(heights[nr][nc]-heights[r][c]));
                    if(neweffort<effort[nr][nc]){
                        effort[nr][nc] = neweffort;
                        pq.push({ effort[nr][nc],{nr,nc}});
                    }
                    
                }
            }
        }

        return effort[n-1][m-1];

    }
};
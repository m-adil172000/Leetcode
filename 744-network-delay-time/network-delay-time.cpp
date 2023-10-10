class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>signal(n+1,INT_MAX);

        pq.push({0,k});
        signal[k]=0;

        while(pq.size()>0){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int time = it.first;

            for(auto it:adj[node]){
                int adjtime = it.second;
                int adjnode = it.first;

                if(time + adjtime < signal[adjnode]){
                    signal[adjnode]=time +adjtime;
                    pq.push({signal[adjnode],adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1; i<signal.size(); i++){
            if(signal[i]==INT_MAX) return -1;
            ans = max(ans,signal[i]);
        }
    
        return ans;
    }

};
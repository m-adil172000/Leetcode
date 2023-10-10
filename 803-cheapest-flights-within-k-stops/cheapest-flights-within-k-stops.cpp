class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int c = it[2];
            adj[u].push_back({v,c});
        }


        vector<int>price(n,INT_MAX);
        price[src]=0;
        // to store {price,{station,stops}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});  // we will store {stops,{station,price}}

        while(q.size()>0){
            auto it = q.front();
            q.pop();

            int stop = it.first;
            int station = it.second.first;
            int p = it.second.second;

            if(stop>k) continue;

            for(auto it:adj[station]){
                int adjnode = it.first;
                int adjprice = it.second;

                if(p +  adjprice < price[adjnode] && stop<=k){
                    price[adjnode]=p+adjprice;
                    q.push({stop+1,{adjnode,price[adjnode]}});
                }
            }
        }

        if(price[dst]==INT_MAX) return -1;
        return price[dst];



    }
};


/*

Since in this problem, we have to calculate the minimum cost to reach the destination from the source but with a restriction on the number of stops, we would be using Dijkstra’s Algorithm. Now, one must wonder that based on what parameter we should add elements to the priority queue.

Now, if we store the elements in the priority queue with the priority given to the minimum distance first, then after a few iterations we would realize that the Algorithm will halt when the number of stops would exceed. This may result in a wrong answer as it would not allow us to explore those paths which have more cost but fewer stops than the current answer.

To tackle this issue, we store the elements in terms of the minimum number of stops in the priority queue so that when the algorithm halts, we can get the minimum cost within limits.

Also, a point to note here is that do we really need a priority queue for carrying out the algorithm? The answer for that is No because when we are storing everything in terms of a number of stops, the stops are increasing monotonically which means that the number of sops is increasing by 1 and when we pop an element out of the queue, we are always popping the element with a lesser number of stops first. Replacing the priority queue with a simple queue will let us eliminate an extra log(N) of the complexity of insertion-deletion in a priority queue which would in turn make our algorithm a lot faster.
*/
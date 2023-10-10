/*
Here we can't just add all the shortest path incoming edge to the destination and return as answer because the nodes before the destination might also have more than one way to arrive to themselves.

so, ans != all incoming edges (from shortest path)
instead it will be ans = ways to arrive to previour neighbour1 + neighbour2 + neighbour3 + ...
i.e. ways[node] = ways[node1] + ways[node2] + ways[node3]
*/


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Creating an adjacency list for the given graph.
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<long long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = (int)(1e9 + 7);

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty())
        {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                long long adjNode = it.first;
                long long edW = it.second;

                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode]%mod + ways[node]%mod) % mod;
                }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;

    }
};
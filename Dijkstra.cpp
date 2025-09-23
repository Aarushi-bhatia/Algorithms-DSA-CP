// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected graph (remove if directed)
        }

        // Min-heap (priority queue) for {dist, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            
            if (d > dist[u]) continue; // Skip stale entries
            
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};

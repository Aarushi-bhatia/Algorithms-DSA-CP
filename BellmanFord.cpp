// Purpose : Shortest paths from a single source to all other vertices in a weighted graph (can handle negative weights)
// Has a time complexity of O(V·E) and space complexity of O(V)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 0; i < V-1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // nth relaxation to check negative cycle
        for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                }
            }
        
        return dist;
    }
};

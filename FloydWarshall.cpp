// Purpose: Computes the shortest distances between all pairs of vertices in a weighted graph using the Floyd-Warshall algorithm.
// Time & Space Complexity: Runs in O(n³) time and O(n²) space, where n is the number of vertices.

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int k = 0 ; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0 ; j < n ; j++){
                    if (dist[i][k] < 1e8 && dist[k][j] < 1e8)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

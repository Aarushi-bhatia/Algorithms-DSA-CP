class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < V ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topoOrder;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return topoOrder;
    }
};

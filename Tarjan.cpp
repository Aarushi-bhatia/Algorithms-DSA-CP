// Purpose: Finds all strongly connected components (SCCs) in a directed graph using Tarjan’s algorithm.
// Time & Space Complexity: Runs in O(V + E) time and O(V) space, where V is the number of vertices and E is the number of edges.

class Solution {
public:
    int timer = 0;
    void dfs(int u, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, 
             stack<int>& st, vector<bool>& inStack, vector<vector<int>>& scc) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for(int v : adj[u]){
            if(disc[v] == -1){
                dfs(v, adj, disc, low, st, inStack, scc);
                low[u] = min(low[u], low[v]);
            } else if(inStack[v]){
                low[u] = min(low[u], disc[v]);
            }
        }

        if(low[u] == disc[u]){
            vector<int> component;
            while(true){
                int node = st.top(); st.pop();
                inStack[node] = false;
                component.push_back(node);
                if(node == u) break;
            }
            scc.push_back(component);
        }
    }

    vector<vector<int>> tarjansSCC(int V, vector<vector<int>>& adj) {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        vector<vector<int>> scc;

        for(int i = 0; i < V; i++){
            if(disc[i] == -1)
                dfs(i, adj, disc, low, st, inStack, scc);
        }

        return scc;
    }
};

// Bridge : -  Critical Connections in a Network
//https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    vector<int> disc, low, parent;
    vector<bool> visited;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;
    int time;
    void dfs(int u) {
        visited[u] = true;
        disc[u] = low[u] = time++; 
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        disc = vector<int>(n, -1);  
        low = vector<int>(n, -1);
        parent = vector<int>(n, -1);
        visited = vector<bool>(n, false);
        time = 0;
        for (const auto &conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return bridges;
    }
};
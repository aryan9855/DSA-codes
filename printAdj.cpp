class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(V);  // Create adjacency list for V vertices
        
        for (auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);  // Add v to u's list
            adj[v].push_back(u);  // Add u to v's list (since undirected)
        }
        
        return adj;
    }
};

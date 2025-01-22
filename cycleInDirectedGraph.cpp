//Cycle in a Directed Graph
//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/0
class Solution {
  public:
   bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1; 
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited)) {
                    return true;
                }
            } else if (visited[neighbor] == 1) {
                return true;//mil gaye cycle 
            }
        }

        visited[node] = 2;// fully explored when no neighbor is found
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> visited(V, 0); 
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// User function Template for C++

class Solution {
public:
    void dfs(int node, int parent, int &timer,
             vector<int> &disc, vector<int> &low,
             vector<int> &ap, vector<int> adj[],
             vector<bool> &visited) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int children = 0;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                children++;
                dfs(neighbor, node, timer, disc, low, ap, adj, visited);
                low[node] = min(low[node], low[neighbor]);

                // Case 1: non-root node
                if ( low[neighbor] >= disc[node] && parent != -1 ) {
                    ap[node] = 1;
                }
            } else {
                // Back edge
                low[node] = min(low[node], disc[neighbor]);
            }
        }

        // Case 2: root node with 2 or more children
        if (parent == -1 && children > 1) {
            ap[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1), ap(V, 0);
        vector<bool> visited(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, disc, low, ap, adj, visited);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};  // If no articulation point
        return result;
    }
};

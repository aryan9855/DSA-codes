class Solution {
public:
    bool isSafe(int newx, int newy, vector<vector<bool>> &visit, vector<vector<int>> &mat, int n) {
        return (newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
               !visit[newx][newy] && mat[newx][newy] == 1;
    }

    void solve(int x, int y, vector<vector<int>> &mat, int n, vector<string> &ans,
               vector<vector<bool>> &visit, string path) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visit[x][y] = true;

        if (isSafe(x + 1, y, visit, mat, n)) {
            solve(x + 1, y, mat, n, ans, visit, path + 'D');
        }

        if (isSafe(x, y - 1, visit, mat, n)) {
            solve(x, y - 1, mat, n, ans, visit, path + 'L');
        }

        if (isSafe(x, y + 1, visit, mat, n)) {
            solve(x, y + 1, mat, n, ans, visit, path + 'R');
        }

        if (isSafe(x - 1, y, visit, mat, n)) {
            solve(x - 1, y, mat, n, ans, visit, path + 'U');
        }

        visit[x][y] = false;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        string path = "";

        if (mat[0][0] == 0) {
            return ans;
        }

        solve(0, 0, mat, n, ans, visit, path);
        return ans;
    }
};

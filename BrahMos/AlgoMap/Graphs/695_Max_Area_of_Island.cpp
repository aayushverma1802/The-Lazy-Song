class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis,
            int n, int m, int& count) {
        if (i < 0 or j < 0 or i >= n or j >= m or vis[i][j] == true or
            grid[i][j] == 0) {
            return 0;
        }
        vis[i][j] = true;
        count++;

        dfs(i + 1, j, grid, vis, n, m, count);
        dfs(i, j + 1, grid, vis, n, m, count);
        dfs(i - 1, j, grid, vis, n, m, count);
        dfs(i, j - 1, grid, vis, n, m, count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false and grid[i][j] == 1) {
                    // count++;
                    int count = 0;

                    int a = dfs(i, j, grid, vis, n, m, count);
                    maxi = max(maxi, a);
                }
            }
            // count = 0;
        }
        return maxi;
    }
};
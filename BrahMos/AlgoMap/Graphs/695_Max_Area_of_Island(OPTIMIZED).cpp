class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int count = 1;
        count += dfs(i + 1, j, grid, n, m);
        count += dfs(i, j + 1, grid, n, m);
        count += dfs(i - 1, j, grid, n, m);
        count += dfs(i, j - 1, grid, n, m);
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        // int count = 1;         
        int maxi = 0; 
        // vector<vector<bool>> vis(n, vector<bool>(m, false));         
        for (int i = 0; i < n; i++) {             
            for (int j = 0; j < m; j++) { 
                if (grid[i][j] == 1) { 
                    // count++; 
                    int a = dfs(i, j, grid, n, m); 
                    maxi = max(maxi, a); 
                } 
            }             
            // count = 0;         
        } 
        return maxi;     
    } 
};

class Solution:
    def solve(self, i, j1, j2, grid, n, m,dp):
        if j1 < 0 or j1 >= m or j2 < 0 or j2 >= m:
            return float("-inf")
        if dp[i][j1][j2]!=-1:
            return dp[i][j1][j2]
        if i == n - 1:
            if j1 == j2:
                return grid[i][j1]
            return grid[i][j1] + grid[i][j2]

        maxi = float("-inf")

        for nj1 in range(-1, 2):
            for nj2 in range(-1, 2):
                if j1 == j2:
                    ans = grid[i][j1] + self.solve(i+1, j1+nj1, j2+nj2, grid, n, m,dp)
                else:
                    ans = grid[i][j1] + grid[i][j2] + self.solve(i+1, j1+nj1, j2+nj2, grid, n, m,dp)
                maxi = max(maxi, ans)
        dp[i][j1][j2]=maxi
        return dp[i][j1][j2]

    def cherryPickup(self, grid):
        n = len(grid)
        m = len(grid[0])
        #n*m*m
        dp=[[[-1 for _ in range(m)]for _ in range(m)]for _ in range(n)]
        return self.solve(0, 0, m-1, grid, n, m,dp)

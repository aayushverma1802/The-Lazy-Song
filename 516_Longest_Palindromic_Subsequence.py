class Solution:
    def solve(self, s, r, n, m, i, j, dp):
        if i == n or j == m:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if s[i] == r[j]:
            dp[i][j] = 1 + self.solve(s, r, n, m, i+1, j+1, dp)
        else:
            dp[i][j] = max(
                self.solve(s, r, n, m, i+1, j, dp),
                self.solve(s, r, n, m, i, j+1, dp)
            )

        return dp[i][j]

    def longestPalindromeSubseq(self, s: str) -> int:
        r = s[::-1]
        n = len(s)
        dp = [[-1]*n for _ in range(n)]
        return self.solve(s, r, n, n, 0, 0, dp)
from typing import List
from functools import lru_cache

class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)

        # prefix sum
        colPrefSum = [[0]*(n+1) for _ in range(n+1)]
        for col in range(1, n+1):
            for row in range(1, n+1):
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1]

        @lru_cache(None)
        def solve(prevTaken, prevHeight, col):
            if col == n:
                return 0

            result = 0

            for height in range(n+1):
                prevColScore = 0
                currColScore = 0

                if (not prevTaken) and col-1 >= 0 and height > prevHeight:
                    prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col]

                if prevHeight > height:
                    currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1]

                take = currColScore + prevColScore + solve(True, height, col+1)
                not_take = prevColScore + solve(False, height, col+1)

                result = max(result, take, not_take)

            return result

        return solve(False, 0, 0)
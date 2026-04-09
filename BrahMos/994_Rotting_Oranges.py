from typing import List

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        delrow = [0, 0, -1, 1]
        delcol = [-1, 1, 0, 0]

        n = len(grid)
        m = len(grid[0])

        vis = [[0] * m for _ in range(n)]
        queue = []

        t = 0

        # add all rotten oranges
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    vis[i][j] = 2
                    queue.append((i, j, 0))

        while queue:
            row, col, time = queue.pop(0)
            t = max(t, time)

            for i in range(4):
                left = row + delrow[i]
                right = col + delcol[i]

                if (
                    0 <= left < n and
                    0 <= right < m and
                    vis[left][right] != 2 and
                    grid[left][right] == 1
                ):
                    vis[left][right] = 2
                    queue.append((left, right, time + 1))

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and vis[i][j] != 2:
                    return -1

        return t
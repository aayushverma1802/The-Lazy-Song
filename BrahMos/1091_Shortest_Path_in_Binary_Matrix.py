import heapq
class Solution:
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1

        directions = [(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]
        dist = [[float('inf')] * n for _ in range(n)]
        dist[0][0] = 1

        heap = [(1, 0, 0)]  # (distance, row, col)

        while heap:
            d, r, c = heapq.heappop(heap)

            if (r, c) == (n-1, n-1):
                return d

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                    if d + 1 < dist[nr][nc]:
                        dist[nr][nc] = d + 1
                        heapq.heappush(heap, (d + 1, nr, nc))

        return -1

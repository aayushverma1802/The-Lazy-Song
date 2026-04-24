from collections import defaultdict, Counter
from typing import List

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        parent = list(range(n))

        # DSU find with path compression
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        # DSU union
        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[py] = px

        # Build components
        for u, v in allowedSwaps:
            union(u, v)

        # Group frequency
        groupFreq = defaultdict(Counter)
        for i in range(n):
            root = find(i)
            groupFreq[root][source[i]] += 1

        # Calculate answer
        ans = 0
        for i in range(n):
            root = find(i)
            if groupFreq[root][target[i]] > 0:
                groupFreq[root][target[i]] -= 1
            else:
                ans += 1

        return ans
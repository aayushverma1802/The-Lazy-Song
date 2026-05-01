from typing import List

class Solution:
    def solve(self, k, nums, n, dp, total_sum):
        if k == 0:
            # compute F(0)
            total = 0
            for i in range(n):
                total += i * nums[i]
            dp[0] = total
            return total

        if dp[k] != -1:
            return dp[k]

        prev = self.solve(k - 1, nums, n, dp, total_sum)

        dp[k] = prev + total_sum - n * nums[n - k]

        return dp[k]

    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        total_sum = sum(nums)

        maxi = float('-inf')

        for k in range(n):
            val = self.solve(k, nums, n, dp, total_sum)
            maxi = max(maxi, val)

        return maxi
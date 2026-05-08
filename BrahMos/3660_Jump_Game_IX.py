class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:

        n = len(nums)

        # maxLeft[i] = max element from index 0 to i
        maxLeft = [0] * n

        # minRight[i] = min element from index i to n-1
        minRight = [0] * n

        maxLeft[0] = nums[0]
        minRight[n - 1] = nums[n - 1]

        for i in range(1, n):
            maxLeft[i] = max(nums[i], maxLeft[i - 1])

        for i in range(n - 2, -1, -1):
            minRight[i] = min(nums[i], minRight[i + 1])

        ans = [0] * n

        ans[n - 1] = maxLeft[n - 1]

        for i in range(n - 2, -1, -1):

            # can't go to right at all
            if maxLeft[i] <= minRight[i + 1]:
                ans[i] = maxLeft[i]
            else:
                ans[i] = ans[i + 1]

        return ans
class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        limit=0
        ans=[-1]*len(nums)
        for index, i in enumerate(nums):
            for j in range(i):
                if((j | (j+1))==i):
                    # ans.append(j)
                    ans[index]=j
                    break
                
        return ans


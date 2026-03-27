class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        ans=[]
        nums.sort()
        while nums:
            alice=(nums.pop(0))
            bob=(nums.pop(0))
            ans.append(bob)
            ans.append(alice)
        return ans

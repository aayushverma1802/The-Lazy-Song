import math 
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        mini,index,ans=sys.maxsize,0,0
        for i,num in enumerate(nums):
            temp=abs(num)
            if mini>temp:
                ans=num
                mini=temp
            elif mini==temp:
                if num>ans:
                    ans=num
        return ans


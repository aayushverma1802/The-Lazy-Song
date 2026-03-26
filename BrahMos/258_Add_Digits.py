class Solution:
    def addDigits(self, num: int) -> int:

        while num>=10 :
            ans=0
            a=num%10
            num//=10
            ans+=a
            num=ans
        
        return ans
class Solution:
    def binaryGap(self, n: int) -> int:
        int_num=bin(n)[2:]
        ans=0
        j=0
        for i,num in enumerate(int_num):
            if num=='1':
                j=i+1
                while j<len(int_num):
                    if int_num[j]=='1':
                        ans=max(ans,j-i)
                        break
                    j+=1

        return ans

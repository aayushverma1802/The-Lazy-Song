class Solution:
    def countDigits(self, num: int) -> int:
        s=list()
        temp=num
        while(temp!=0):
            s.append(temp%10)
            temp//=10
        cnt=0
        for i in s:
            if(num%i==0):
                cnt+=1
        return cnt
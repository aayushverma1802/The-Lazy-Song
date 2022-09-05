class Solution:
    def frequencySort(self, s: str) -> str:
        ans=""
        dic={}
        for char in s:
            dic[char] = 0
        for cnt,i in enumerate(s):
            dic[i]+=1
            # print(str(dic[i]) + i )

        sorted_chars = sorted_chars = sorted(dic.items(), key=lambda x: x[1], reverse=True)
        for key,values in sorted_chars:
            # print(ans+" "+str(values)+'\n')
            ans+=key*(values)
        return ans
# ''.join(sorted(s, key=lambda ch: s.count(ch), reverse=True))
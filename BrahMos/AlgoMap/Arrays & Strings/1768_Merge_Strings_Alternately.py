class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n=len(word1)
        m=len(word2)
        i=j=0
        ans=[]
        while(i<n or j<m):
            if(i<n):
                ans.append(word1[i])
                i+=1
            if(j<m):
                ans.append(word2[j])
                j+=1
        return "".join(ans)
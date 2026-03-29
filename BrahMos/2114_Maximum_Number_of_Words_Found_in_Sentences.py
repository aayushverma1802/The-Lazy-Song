class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        ans=max(len(s.split()) for s in sentences)
        return ans
        

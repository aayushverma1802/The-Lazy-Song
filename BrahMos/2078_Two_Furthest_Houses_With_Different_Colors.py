class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        maxi=float('-inf')
        for indexi,i in enumerate(colors):
            for indexj,j in enumerate(colors):
                if i!=j:
                    maxi=max(maxi,abs(indexj-indexi))
        return maxi

from collections import defaultdict
import bisect
from typing import  List
class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n=len(nums)
        # Store indices for each value
        pos=defaultdict(list)
        for i in range(n):
            pos[nums[i]].append(i)
        ans=[]

        for q in queries:
            lst=pos[nums[q]]
            if len(lst)==1:
                ans.append(-1)
                continue
            idx=bisect.bisect_left(lst,q)
            res=float('inf')
            # Check left neighbor
            if idx>0:
                i=lst[idx-1]
                d=abs(i-q)
                res=min(res,d,n-d)
            # check right neighbor
            if idx < len(lst) - 1:
                i = lst[idx + 1]
                d = abs(i - q)
                res = min(res, d, n - d)
            # Circular check(first and last check)
                       # circular only when needed
            if idx == 0:
                i = lst[-1]
                d = abs(i - q)
                res = min(res, d, n - d)

            if idx == len(lst) - 1:
                i = lst[0]
                d = abs(i - q)
                res = min(res, d, n - d)

            ans.append(res)
        return ans
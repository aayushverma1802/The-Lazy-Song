class Solution:
    def firstUniqChar(self, s: str) -> int:
        mp={}
        for index,st in enumerate(s):
            mp[st] = mp.get(st, 0) + 1
        for index,val in enumerate(s):
            # print(key)
            if mp[val]==1:
                return index
        return -1

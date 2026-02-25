class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        # Sol 1
        # return sorted(arr, key=lambda x: (bin(x).count('1'), x))
        # Sol 2 
        ans = []
        
        for i in arr:
            num = bin(i)[2:]
            cnt = 0
            
            for ch in num:
                if ch == '1':
                    cnt += 1
                    
            ans.append((cnt, i))
        
        ans.sort()
        
        result = []
        for count, value in ans:
            result.append(value)
            
        return result
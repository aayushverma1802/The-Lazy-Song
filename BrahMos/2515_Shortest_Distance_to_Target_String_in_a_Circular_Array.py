class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        min_right = min_left = float('inf')

        # left direction
        i = startIndex
        step = 0
        while step < n:
            if words[i] == target:
                min_left = step
                break
            i = (i - 1) % n # This is to make it circular 
            step += 1

        # right direction
        i = startIndex
        step = 0
        while step < n:
            if words[i] == target:
                min_right = step
                break
            i = (i + 1) % n # This is to make it circular 
            step += 1

        ans = min(min_left, min_right)
        return ans if ans != float('inf') else -1
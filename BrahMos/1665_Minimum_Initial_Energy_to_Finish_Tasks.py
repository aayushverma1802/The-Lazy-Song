class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        # Energy -> Max energy - actual 
        # But the Max energy > min eng
        # sort
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)
        answer=0
        current_energy=0
        for actual,minimum in tasks:
            if current_energy<minimum:
                extra=minimum-current_energy
                answer+=extra
                current_energy+=extra
            current_energy-=actual
        return answer
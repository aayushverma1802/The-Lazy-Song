class Solution:

    n=m=0
    direc={
        1:[(0,-1),(0,1)],
        2:[(-1,0),(1,0)],
        3:[(0,-1),(1,0)],
        4:[(0,1),(1,0)],
        5:[(0,-1),(-1,0)],
        6:[(-1,0),(0,1)]
    }
    def dfs(self,grid:List[List[int]],vis,i,j):
        if(i==self.n-1 and j==self.m-1):
            return True
        vis[i][j]=True
        for path in self.direc[grid[i][j]]:
            new_i=i+path[0]
            new_j=j+path[1]
            # correct boundary + visited check
            if not (0 <= new_i < self.n and 0 <= new_j < self.m):
                continue
            if vis[new_i][new_j]:
                continue
            # Important = u can come back i and j from new_i and new_j
            for backdir in self.direc[grid[new_i][new_j]]:
                if(new_i+backdir[0]==i and new_j+backdir[1]==j):
                    if(self.dfs(grid,vis,new_i, new_j)):
                        return True
        return False

    def hasValidPath(self, grid: List[List[int]]) -> bool:
        self.n=len(grid)
        self.m=len(grid[0])
        vis=[[False for _ in range(self.m)] for _ in range(self.n)]
        return self.dfs(grid,vis,0,0)

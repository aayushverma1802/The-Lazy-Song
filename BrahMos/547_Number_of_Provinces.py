class Solution:
    def dfs(self,node,adj,vis:List[bool])->None:

        vis[node]=True
        for i in adj[node]:
            if vis[i]==False:
                self.dfs(i,adj,vis)
        
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        cnt:int=0
        n=len(isConnected)
        m=len(isConnected[0])
        vis=[False]*(n+1)
        # Make the adjaceny matrix
        adj=[[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if (isConnected[i][j]==1 and i!=j):
                    adj[i].append(j)
                    adj[j].append(i)
        for i in range(n):
            if(vis[i]==False):
                cnt+=1
                self.dfs(i,adj,vis)
        return cnt

        
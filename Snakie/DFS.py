def dfs(node,ans,visited,adj):
    visited[node]=True
    ans.append(node)
    for i in adj[node]:
        if(visited[i]==False):
            dfs(i,ans,visited,adj)
    
    return ans
    
    


if __name__=="__main__":
    n=8
    adj=[[],[2,4],[1,3,6],[2],[1,5,7],[4,8],[2],[4,8],[5,7]]
    visited=[0]*(n+1)
    ans=[]
    print(dfs(1,ans,visited,adj))
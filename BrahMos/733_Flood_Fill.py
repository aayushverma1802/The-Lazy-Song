class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        n=len(image)
        m=len(image[0])
        value=image[sr][sc]
        row=[0,0,-1,1]
        col=[-1,1,0,0]
        image[sr][sc]=color
        queue=[]
        if value == color:
            return image
        queue.append((sr,sc))
        while  queue:
            a,b=queue.pop(0)
            for i in range(4):
                nrow=a+row[i]
                ncol=b+col[i]
                if (nrow<n and nrow>=0 and ncol<m and ncol>=0 and image[nrow][ncol]==value):
                    image[nrow][ncol]=color
                    queue.append((nrow,ncol))
                
                
        return image
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    ans=float('-inf')
    def Height(self, root: Optional[TreeNode])-> int:
        if root==None:
            return 0
        l=self.Height(root.left)
        if l<0:
            l=0  
        r=self.Height(root.right)
        if r<0:
            r=0
        self.ans=max(self.ans,l+r+root.val)
        return max(l,r)+root.val
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if root==None:
            return 0
        self.Height(root)
        return self.ans
  
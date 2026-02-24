# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode],temp) -> int:
        if not root:
            return 0
        temp=temp*10+root.val
        if root.left is None and root.right is None:
            return int(str(temp), 2)
        
        return self.solve(root.left,temp)+self.solve(root.right,temp)
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        num=self.solve(root,0)
        print(type(num))
        return num

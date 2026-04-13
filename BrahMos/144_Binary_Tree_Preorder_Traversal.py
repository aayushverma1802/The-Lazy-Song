# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Solution 1
    # def __init__(self):
    #     self.ans=[]
    # def inorder(self,root):
    #     if root is None:
    #         return None
    #     self.ans.append(root.val)
    #     self.inorder(root.left)
    #     self.inorder(root.right)
        
    # Solution 2
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        def preorder(root):
            if root is None:
                return
            ans.append(root.val)
            preorder(root.left)
            preorder(root.right)

        preorder(root)
        return ans
        
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool isSameTree(TreeNode* root ,TreeNode *sub){
    if(root==nullptr and sub==NULL){
        return true;
    }
    if(root==nullptr or sub==nullptr){
        return false;
    }
    if(root->val!=sub->val){
        return false;
    }
    return isSameTree(root->left,sub->left) and 
    isSameTree(root->right,sub->right);

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }
        if(isSameTree(root,subRoot)){
            return true;
        }
       return isSubtree(root->left,subRoot) or
        isSubtree(root->right,subRoot);
        
    }
};
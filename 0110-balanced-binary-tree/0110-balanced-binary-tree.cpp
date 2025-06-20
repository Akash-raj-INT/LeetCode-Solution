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
    bool isBalanced(TreeNode* root) {
       if(root==NULL) return true;
       if(preorder(root)==-1) return false;
       return true;
       
    }
    int preorder(TreeNode* root){
        if(root == NULL) return 0;
        int left = preorder(root->left);
        int right = preorder(root->right);

        if(left == -1 || right == -1 || abs(left-right) >1)  return -1;
        return max(left,right)+1;
    }

};
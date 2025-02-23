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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;  // Store postorder indices
        }
        int preIndex = 0;
        return buildTree(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, 
                        int& preIndex, int postStart, int postEnd) {
        if (preIndex >= preorder.size() || postStart > postEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);  // Create the root
        
        if (postStart == postEnd || preIndex >= preorder.size()) return root; // Base case
        
        int leftChildIdx = postIndex[preorder[preIndex]]; // Find left child in postorder
        
        // Recursively construct left and right subtrees
        root->left = buildTree(preorder, postorder, postIndex, preIndex, postStart, leftChildIdx);
        root->right = buildTree(preorder, postorder, postIndex, preIndex, leftChildIdx + 1, postEnd - 1);
        
        return root;
    }
};

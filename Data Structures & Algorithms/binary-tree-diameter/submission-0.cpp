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
    int diameterOfBinaryTreeHelper(TreeNode* root, int &maxDiameter){
        if (!root)
            return 0;

        int leftDepth = diameterOfBinaryTreeHelper(root->left, maxDiameter);
        int rightDepth = diameterOfBinaryTreeHelper(root->right, maxDiameter);
        int maxDepth = max(leftDepth, rightDepth);
    
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return 1 + maxDepth;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameterOfBinaryTreeHelper(root, maxDiameter);
        return maxDiameter;
    }
};

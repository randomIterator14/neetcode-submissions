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
    int isBalancedHelper(TreeNode* root, bool& isBalanced) {
        if (!root)
            return 0;
        int lh = isBalancedHelper(root->left, isBalanced);
        int rh = isBalancedHelper(root->right, isBalanced);
        if (abs(lh - rh) > 1)
            isBalanced = false;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        isBalancedHelper(root, isBalanced);
        return isBalanced;
    }
};

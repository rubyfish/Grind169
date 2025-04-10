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
    bool checkNode(TreeNode* node, TreeNode* min_node, TreeNode* max_node){
        if (!node)
            return true;
        if ((min_node && node->val <= min_node->val) || 
            (max_node && node->val >= max_node->val))
            return false;
        return checkNode(node->left, min_node, node) &&
               checkNode(node->right, node, max_node);
    }
    bool isValidBST(TreeNode* root) {
        return checkNode(root, nullptr, nullptr);
    }
};
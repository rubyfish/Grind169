/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = std::min(p->val, q->val);
        int high = std::max(p->val, q->val);

        if (root->val >= low && root->val<=high){
            return root;
        }
        else if (root->val > high){
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);
    }
};
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
        int q_val = q->val;
        int p_val = p->val;
        TreeNode* node = root;
        while(node){
            if (node->val < p_val && node->val < q_val){
                node = node->right;
            }
            else if (node->val > p_val && node->val > q_val){
                node = node->left;
            }
            else{
                return node;
            }
        }

        return NULL;
    }
};
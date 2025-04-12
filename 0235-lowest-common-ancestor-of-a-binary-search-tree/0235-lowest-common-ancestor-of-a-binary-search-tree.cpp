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
        TreeNode* curr_node = root;

        while (curr_node){
            if (curr_node -> val > p -> val && curr_node -> val > q -> val)
                curr_node = curr_node -> left;
            else if (curr_node -> val < p -> val && curr_node -> val < q -> val)
                curr_node = curr_node -> right;
            else
                return curr_node;
        }

        return nullptr;
    }
};
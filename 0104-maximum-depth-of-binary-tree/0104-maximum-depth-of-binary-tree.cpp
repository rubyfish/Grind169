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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int q_size = q.size();
            while (q_size > 0){
                TreeNode* node = q.front();
                q.pop();

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);

                q_size--;
            }

            count++;
        }

        return count;
    }
};
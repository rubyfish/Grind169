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
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        countMaxSum(root);
        return max_sum;
    }
private:
    int max_sum = INT_MIN;
    int countMaxSum(TreeNode* node){
        if (!node)
            return 0;
        
        int left_max_sum = std::max(countMaxSum(node -> left), 0);
        int right_max_sum = std::max(countMaxSum(node -> right), 0);
        int cur_max_sum = (node -> val, node -> val + left_max_sum + right_max_sum);
        max_sum = std::max(max_sum, cur_max_sum);

        return max(left_max_sum + node -> val, right_max_sum + node -> val);
    }
};
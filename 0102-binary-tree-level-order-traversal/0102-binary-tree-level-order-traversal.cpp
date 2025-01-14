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
    void bfs(TreeNode* root, vector<vector<int>>& results, int level) {
        if (root == nullptr)
            return;
        if (results.size() == level)
            results.push_back(vector<int>());
        results[level].push_back(root->val);
        
        bfs(root->left, results, level+1);
        bfs(root->right, results, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        bfs(root, results, 0);

        return results;
    }
};
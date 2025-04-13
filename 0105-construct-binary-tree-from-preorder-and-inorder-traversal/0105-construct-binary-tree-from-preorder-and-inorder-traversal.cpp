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
    unordered_map<int, int> map;
    int preorder_index = 0;
    vector<int> _preorder;
    TreeNode* constructTree(vector<int>& inorder, int left, int right){
        if (left > right || left < 0 || right >= _preorder.size() || preorder_index + 1 > _preorder.size()) return nullptr;
        
        TreeNode* node = new TreeNode(_preorder[preorder_index++]);
        node -> left = constructTree(inorder, left, map[node -> val] - 1);
        node -> right = constructTree(inorder, map[node -> val] + 1, right);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        _preorder = preorder;
        for (int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }

        return constructTree(inorder, 0, inorder.size() - 1);
    }
};
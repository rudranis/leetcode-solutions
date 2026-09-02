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
#include <algorithm>

class Solution {
private:
    int cameras = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 1;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 2 || right == 2) {
            cameras++;
            return 0;
        }

        if (left == 0 || right == 0) {
            return 1;
        }

        return 2;
    }

public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 2) {
            cameras++;
        }
        return cameras;
    }
};
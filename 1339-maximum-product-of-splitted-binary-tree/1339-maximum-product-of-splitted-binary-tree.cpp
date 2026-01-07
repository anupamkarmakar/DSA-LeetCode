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
    long long totalSum=0;
    long long maxSum=0;
    const int MOD = 1e9+7;

    long long totalsum(TreeNode* root){
        if(!root) return 0;

        return root->val + totalsum(root->left) + totalsum(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subtreeSum = root->val + left + right;

        maxSum = max(maxSum, subtreeSum*(totalSum-subtreeSum));

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = totalsum(root);
        dfs(root);

        return maxSum%MOD; 
    }
};
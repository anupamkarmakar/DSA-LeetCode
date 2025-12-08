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
    void inorderRec(TreeNode* temp, vector<int> &ans){
        if(temp==nullptr) return;

        inorderRec(temp->left,ans);
        ans.push_back(temp->val);
        inorderRec(temp->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderRec(root,inorder);
        
        return inorder;
    }
};
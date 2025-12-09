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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastVisited=nullptr;

        while(root || !st.empty()){
            // 1) Go to extreme left
            while(root){
                st.push(root);
                root=root->left;
            }
            // 2) Look at the top (do NOT pop yet)
            root=st.top();

            // 3) If there is a right child and it is not processed yet
            if(root->right && root->right!=lastVisited){
                root=root->right;          // go right
            }
            // 4) Right child is null OR already processed
            else{
                ans.push_back(root->val);   // process current node
                lastVisited=root;           // mark as processed
                st.pop();                   // now pop from stack
                root=nullptr;               // avoid re-entering left loop immediately
            }
        }
        return ans;
    }
};
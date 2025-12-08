class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};

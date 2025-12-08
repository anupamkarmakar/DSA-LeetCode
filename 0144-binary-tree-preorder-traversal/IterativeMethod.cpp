class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<TreeNode*> st;
        while(!st.empty() || root!=nullptr){
            if(root!=nullptr){
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            else{
                root=st.top();
                st.pop();
                root=root->right;
            }
        }
        return ans;
    }
};
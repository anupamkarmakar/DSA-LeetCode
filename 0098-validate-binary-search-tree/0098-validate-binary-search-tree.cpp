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

//  GPT DRY RUN LINK : https://chatgpt.com/share/6937d95b-99c4-8004-871e-85970154efe6

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long long prev=LLONG_MIN;

        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }

            root=st.top();
            st.pop();

            if(root->val<=prev) return false;
            prev=root->val;

            root=root->right;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> result;
    void rec(TreeNode* node, int level){
        if(!node) return;

        if(level==result.size()){
            result.push_back({});
        }

        result[level].push_back(node->val);

        rec(node->left,level+1);
        rec(node->right,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        rec(root,0);
        return result;
    }
};
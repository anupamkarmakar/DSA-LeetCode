class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans,"",0,0,n);
        return ans;
    }

    void backtrack(vector<string> &ans, string cur, int start, int close, int n){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return;
        }

        if(start<n) backtrack(ans,cur+"(",start+1,close,n);
        if(close<start) backtrack(ans,cur+")",start,close+1,n);
    }
};
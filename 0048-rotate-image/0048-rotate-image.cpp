class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        vector<vector<int>> trans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                trans[j][i]=matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            reverse(trans[i].begin(),trans[i].end());
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=trans[i][j];
            }
        }
    }
};
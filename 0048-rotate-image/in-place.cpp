class Solution {
public:
    // It doesn't take extra space
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        // transpose the matrix inplace
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reverse the each row wise element
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
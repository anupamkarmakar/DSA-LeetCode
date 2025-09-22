class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowFlag(m, 0);
        vector<int> colFlag(n, 0);

        // Step 1: mark rows and cols that have zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowFlag[i] = 1;
                    colFlag[j] = 1;
                }
            }
        }

        // Step 2: set zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowFlag[i] || colFlag[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

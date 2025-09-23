class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(); //No of rows
        int n=matrix[0].size();  // No of columns

        int top=0,bottom=m-1;
        int left=0,right=n-1;

        vector<int> ans;

        while(top<=bottom && left<=right){
            //left to right
            for(int j=left;j<=right;j++){ // i th position fixed
                ans.push_back(matrix[top][j]);
            }
            top++;

            //top->bottom
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //right->left
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // bottom->top
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
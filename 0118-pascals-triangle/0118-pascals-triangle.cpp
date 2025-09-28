class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(genrow(i));
        }
        return ans;
    }

    vector<int> genrow(int row){
        vector<int>ansRow;
        int ele=1;
        ansRow.push_back(ele);
        for(int i=1;i<=row;i++){
            ele=ele*(row-i+1);
            ele=ele/i;
            ansRow.push_back(ele);  
        }
        return ansRow;

    }
};
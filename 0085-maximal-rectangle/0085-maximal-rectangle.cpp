class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxArea=0,nse,pse,idx;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                idx=st.top();
                st.pop();
                nse=i;
                pse=st.empty() ? -1 : st.top();
                maxArea=max(maxArea,(heights[idx]*(nse-pse-1)));
            }
            st.push(i);
        }

        while(!st.empty()){
            nse=n;
            idx=st.top();
            st.pop();
            pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,(heights[idx]*(nse-pse-1)));
        }

        return maxArea;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(); //No of row 
        int m= matrix[0].size(); //No of coloum
        int maxArea=0;
        vector<vector<int>>preSum(n,vector<int>(m,0)); //PrefixSum

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1') sum+=1;
                else sum=0;
                preSum[i][j]=sum;
            }
        }

        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestRectangleArea(preSum[i]));
        }
        return maxArea;
    }
};
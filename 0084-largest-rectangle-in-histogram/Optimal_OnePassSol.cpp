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
};
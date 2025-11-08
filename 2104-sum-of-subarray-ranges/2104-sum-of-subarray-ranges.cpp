class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        vector<int> minPrev(n,-1);
        vector<int> maxPrev(n,-1);
        vector<int> minNext(n,-1);
        vector<int> maxNext(n,-1);
        stack<int> st;

        // Create previous minimum ele of array
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            minPrev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Next minimum ele of array
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            minNext[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Create previous maximum ele of array
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            maxPrev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Next maximum ele of array
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            maxNext[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;
            long long leftMax=i-maxPrev[i],rightMax=maxNext[i]-i;
            res+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
        }
        return res;
    }
};
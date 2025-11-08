class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minPrev(n), minNext(n), maxPrev(n), maxNext(n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            minPrev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            minNext[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            maxPrev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            maxNext[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate result
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long leftMin = i - minPrev[i], rightMin = minNext[i] - i;
            long long leftMax = i - maxPrev[i], rightMax = maxNext[i] - i;
            res += (leftMax * rightMax - leftMin * rightMin) * nums[i];
        }
        return res;
    }
};

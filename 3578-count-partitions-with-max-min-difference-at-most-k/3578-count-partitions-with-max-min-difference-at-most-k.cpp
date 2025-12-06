class Solution {
using int64 = long long;
const int MOD = 1e9 + 7;

public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int64> dp(n+1, 0), pref(n+1, 0); // dp[0..n], pref[i] = sum dp[0..i]
        dp[0] = 1;
        pref[0] = 1;

        deque<int> dqMax, dqMin; // store indices, maintain decreasing for max, increasing for min
        int L = 0; // left index of current window (0-based)
        for (int i = 0; i < n; ++i) {
            // add nums[i]
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[i]) dqMax.pop_back();
            dqMax.push_back(i);
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[i]) dqMin.pop_back();
            dqMin.push_back(i);

            // move L while window invalid
            while (L <= i && nums[dqMax.front()] - nums[dqMin.front()] > k) {
                // if the leftmost index equals front, pop it
                if (dqMax.front() == L) dqMax.pop_front();
                if (dqMin.front() == L) dqMin.pop_front();
                ++L;
            }

            // now window [L..i] satisfies max-min <= k
            // dp[i+1] = sum_{t=L..i} dp[t]  where dp indices are shifted: dp prefix sums used
            // pref[x] = sum dp[0..x]
            // dp[i+1] = pref[i] - pref[L-1]
            int64 leftPrefIndex = (L - 1 >= 0) ? pref[L - 1] : 0;
            dp[i+1] = (pref[i] - leftPrefIndex) % MOD;
            if (dp[i+1] < 0) dp[i+1] += MOD;
            pref[i+1] = (pref[i] + dp[i+1]) % MOD;
        }

        return (int)(dp[n] % MOD);
    }
};
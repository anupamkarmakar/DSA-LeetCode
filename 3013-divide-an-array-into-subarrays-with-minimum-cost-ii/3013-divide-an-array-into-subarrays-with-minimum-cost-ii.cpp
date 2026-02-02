class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();
        if (k == 1) return nums[0];

        int m = k - 1;
        int w = dist + 1;
        int available = n - 1;

        // If window size exceeds available, just use the whole nums[1..]
        w = min(w, available);

        multiset<int> small, large;
        long long sumSmall = 0;

        auto rebalance = [&]() {
            while ((int)small.size() > m) {
                auto it = prev(small.end());
                int val = *it;
                small.erase(it);
                sumSmall -= val;
                large.insert(val);
            }
            while ((int)small.size() < m && !large.empty()) {
                auto it = large.begin();
                int val = *it;
                large.erase(it);
                small.insert(val);
                sumSmall += val;
            }
        };

        auto add = [&](int x) {
            if ((int)small.size() < m) {
                small.insert(x);
                sumSmall += x;
            } else {
                if (!small.empty() && x <= *prev(small.end())) {
                    small.insert(x);
                    sumSmall += x;
                } else {
                    large.insert(x);
                }
            }
            rebalance();
        };

        auto remove = [&](int x) {
            auto it = small.find(x);
            if (it != small.end()) {
                small.erase(it);
                sumSmall -= x;
            } else {
                it = large.find(x);
                if (it != large.end()) large.erase(it);
            }
            rebalance();
        };

        // build initial window on nums[1..w]
        for (int i = 1; i <= w; ++i) add(nums[i]);

        long long ans = nums[0] + sumSmall;

        // slide window over nums[1..]
        for (int s = 2; s + w - 1 <= n - 1; ++s) {
            remove(nums[s - 1]);
            add(nums[s + w - 1]);
            ans = min(ans, nums[0] + sumSmall);
        }

        return ans;
    }
};

class Solution {
public:
    typedef long long ll;

    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int j = 0;
        int minRemove = n;   // worst case remove all

        for (int i = 0; i < n; i++) {
            while (j < n && (ll)nums[j] <= (ll)nums[i] * k) {
                j++;
            }

            int keep = j - i;
            minRemove = min(minRemove, n - keep);
        }

        return minRemove;
    }
};

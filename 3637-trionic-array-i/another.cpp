class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0) return false; // no increasing part

        int peak1 = i;

        // phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == peak1) return false; // no decreasing part

        int valley = i;

        // phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == valley) return false; // no second increasing part

        return i == n - 1;
    }
};

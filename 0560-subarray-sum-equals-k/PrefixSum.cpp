class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case: empty prefix

        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;

            // check if (sum - k) has appeared before
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }

            // store/update prefix sum frequency
            prefixCount[sum]++;
        }

        return count;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
    vector<int> last(256, -1); // last index seen for each ASCII char
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        unsigned char c = s[right];
        if (last[c] >= left) {
            left = last[c] + 1;
        }
        last[c] = right;
        best = max(best, right - left + 1);
    }
    return best;
}
};
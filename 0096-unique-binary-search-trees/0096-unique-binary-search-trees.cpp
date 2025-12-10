class Solution {
public:
    long long nCr(int n, int r) {
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
        }
        return ans;
    }

    int numTrees(int n) {
        long long catalan = nCr(2*n, n) / (n + 1);
        return (int)catalan;
    }
};

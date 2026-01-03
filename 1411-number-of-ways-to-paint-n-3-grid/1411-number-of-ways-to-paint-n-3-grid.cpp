class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long abc = 6;  // ABC pattern
        long long aba = 6;  // ABA pattern

        for (int i = 2; i <= n; i++) {
            long long new_abc = (2 * abc + 2 * aba) % MOD;
            long long new_aba = (2 * abc + 3 * aba) % MOD;

            abc = new_abc;
            aba = new_aba;
        }

        return (abc + aba) % MOD;
    }
};

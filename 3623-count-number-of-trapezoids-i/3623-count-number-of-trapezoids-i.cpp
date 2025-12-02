class Solution {
public:
    const long long MOD = 1000000007;

    long long comb2(long long n){
        if(n < 2) return 0;
        return (n * (n - 1) / 2) % MOD;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 4) return 0;

        unordered_map<int,long long> freq;
        for(int i = 0; i < n; i++){
            freq[points[i][1]]++;
        }

        vector<long long> x;
        for(auto &p : freq){
            x.push_back(comb2(p.second));
        }

        long long sum = 0, sumSq = 0;
        for(long long v : x){
            sum = (sum + v) % MOD;
            sumSq = (sumSq + (v * v) % MOD) % MOD;
        }

        // result = (sum^2 - sumSq) / 2 % MOD
        long long result = ((sum * sum % MOD) - sumSq + MOD) % MOD;
        result = (result * ((MOD + 1) / 2)) % MOD;  // multiply by inverse of 2 mod MOD

        return (int)result;
    }
};

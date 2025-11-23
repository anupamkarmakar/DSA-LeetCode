class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> r1, r2;

        for(int n : nums) {
            total += n;
            if(n % 3 == 1) r1.push_back(n);
            else if(n % 3 == 2) r2.push_back(n);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if(total % 3 == 0) return total;

        int ans = 0;
        if(total % 3 == 1) {
            int remove1 = r1.size() > 0 ? r1[0] : 1e9;
            int remove2 = r2.size() > 1 ? r2[0] + r2[1] : 1e9;
            ans = total - min(remove1, remove2);
        } else { // total % 3 == 2
            int remove1 = r2.size() > 0 ? r2[0] : 1e9;
            int remove2 = r1.size() > 1 ? r1[0] + r1[1] : 1e9;
            ans = total - min(remove1, remove2);
        }

        return ans;
    }
};

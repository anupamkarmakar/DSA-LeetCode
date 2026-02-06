class Solution {
public:
    typedef long long ll;
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int len=0, minlen=INT_MAX;

        sort(nums.begin(), nums.end());

        int i=0, j=0;
        while(j<n && i<n){
            while(j<n && (ll)nums[i]*k>= (ll)nums[j]){
                j++;
            }

            len = n-(j-i);
            minlen = min(len,minlen);

            i++;
        }

        return minlen;
    }
};
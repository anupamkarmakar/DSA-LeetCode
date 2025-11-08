class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        for(int i=0;i<n;i++){
            int small=nums[i],large=nums[i];
            for(int j=i;j<n;j++){
                small = min(small,nums[j]);
                large = max(large,nums[j]);
                int diff=(large-small);
                ans+=diff;
            }
        }
        return ans;
    }
};
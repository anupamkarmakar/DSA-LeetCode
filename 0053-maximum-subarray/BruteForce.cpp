class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum,maxsum=nums[0];
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                maxsum=max(sum,maxsum);
            }
        }
        return maxsum;
    }
};
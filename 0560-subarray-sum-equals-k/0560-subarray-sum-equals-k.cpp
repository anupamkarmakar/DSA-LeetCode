class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int numSubarray=0;

        for(int i=0;i<n-1;i++){
            if(nums[i]==k) numSubarray++;
            int sum=nums[i];
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(sum==k) numSubarray++;
            }
        }
        if(nums[n-1]==k) numSubarray++;
        return numSubarray;
    }
};
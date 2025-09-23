class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int numSubarray=0;

        for(int i=0;i<n;i++){
            if(nums[i]==k) numSubarray++; //checking whether 1st element is k
            int sum=nums[i]; // initialise sum
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(sum==k) numSubarray++;
            }
        }
        return numSubarray;
    }
};
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int rsum=0,lsum=nums[0];
        for(int i=n-1;i>=1;i--){
            rsum+=nums[i];
        }

        int count=0;
        for(int i=0;i<n-1;i++){
            if((lsum-rsum)%2==0) count++;
            rsum=rsum-nums[i];
            lsum=lsum+nums[i];
        }
        return count;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(),mx=nums[0],idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                idx=i;
            }
        }
        return idx;
    }
};
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=1001,q=1001;
        int idxp=-1,idxq=-1;

        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]) return false;
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                p=nums[i];
                idxp=i;
            }

            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                q=nums[i];
                idxq=i;

                while(i<n-1){
                    if(nums[i]>=nums[i+1]) return false;
                    i++;
                }
            }
        }

        if(idxp!=-1 && idxq!=-1 && idxp<idxq) return true;
        else return false;
    }
};
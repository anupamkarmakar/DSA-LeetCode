class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        if(n==3) return(nums[0]+nums[1]+nums[2]);

        int firstMin=nums[1];
        int secondMin=INT_MAX;

        for(int i=2;i<n;i++){
            if(nums[i]<=firstMin){
                secondMin=firstMin;
                firstMin=nums[i];
            }
            else if(nums[i]>firstMin && nums[i]<secondMin){
                secondMin=nums[i];
            }
        }
        return (nums[0]+firstMin+secondMin);
    }
};
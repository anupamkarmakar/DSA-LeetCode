class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0 ; i<nums.size()-2 ; i++){
            
            // Total n + 1 unique elements among 2n elements, so repeated element repeat after next element or after next element
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2])
                return nums[i];
        }

        return nums[nums.size()-1];
    }
};
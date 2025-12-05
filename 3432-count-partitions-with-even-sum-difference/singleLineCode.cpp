class Solution {
public:
    int countPartitions(vector<int>& nums) {
        if((accumulate(nums.begin(),nums.end(),0))%2) return 0;
        return nums.size()-1;
    }
};
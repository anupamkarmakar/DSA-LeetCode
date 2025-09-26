class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startIdx=(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        int endIdx=(upper_bound(nums.begin(),nums.end(),target)-nums.begin());

        // check if target is not present
        if(startIdx==nums.size() || nums[startIdx]!=target)
            return {-1,-1};

        return {startIdx,endIdx-1};
    }
};
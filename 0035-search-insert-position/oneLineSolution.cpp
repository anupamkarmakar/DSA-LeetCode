class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return(lower_bound(nums.begin(),nums.end(),target) - nums.begin());
    }
};


/* 

1) We can use std::lower_bound, which performs a binary search internally.
2) lower_bound(nums.begin(), nums.end(), target) returns an iterator to the first element that is greater than or equal to target.
3) Subtracting nums.begin() from this iterator gives us the index directly.
4) If target is larger than all elements, it will return nums.size(), meaning the element should be inserted at the end.

*/
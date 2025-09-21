class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Sort the vector
        sort(nums.begin(), nums.end());

        // Step 2: Remove duplicates (unique shifts duplicates to the end)
        auto it = unique(nums.begin(), nums.end());

        // Step 3: Erase the redundant elements
        nums.erase(it, nums.end());
        

        int n=nums.size(),count=1,mxcount=1;

        if(n<2) return n;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                count++;
                mxcount=max(mxcount,count);
            }
            else{
                count=1;
            }
        }
        return mxcount;
    }
};
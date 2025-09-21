class Solution {
public:
    // Brute Force
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1,v2,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }

        int idx1=0,idx2=0;
        while(idx2<nums.size()/2){
            ans.push_back(v1[idx1]);
            idx1++;
            ans.push_back(v2[idx2]);
            idx2++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int j = i;

            if(nums[i] > 0){
                j = (nums[i] + i) % n;
            }

            else if(nums[j] < 0){
                j = (nums[i]%n + i + n) % n;
            }

            else{
                j = i;
            }
            ans.push_back(nums[j]);
        }

        return ans;
    }
};
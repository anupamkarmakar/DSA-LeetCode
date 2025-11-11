class Solution {
public:
    // kandane's Algorithm
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxPdt=nums[0],minPdt=nums[0],ans=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(maxPdt,minPdt); // handle negative number

            maxPdt=max(nums[i], nums[i]*maxPdt); // compare with nums[i],bcz start new subarray not extent subarray
            minPdt=min(nums[i], nums[i]*minPdt);

            ans=max(ans,maxPdt);
        }
        return ans;
    }
};
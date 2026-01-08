class Solution {
public:
    int atmost(vector<int>nums, int k){
        int odd=0,count=0;
        int left=0,right=0;

        // Creating Window
        while(right<nums.size()){
            if(nums[right]%2!=0) odd++;

            // Remain atmost k oddnum in window
            while(odd>k){
                if(nums[left]%2!=0) odd--;
                left++;
            }

            count+=(right-left+1);

            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = atmost(nums,k) - atmost(nums,k-1);
        return ans;
    }
};
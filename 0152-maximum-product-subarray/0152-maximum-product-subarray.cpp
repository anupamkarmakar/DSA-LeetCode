class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            int pdt=1;
            for(int j=i;j<n;j++){
                pdt*=nums[j];
                ans=max(ans,pdt);
            }
        }
        return ans;
    }
};
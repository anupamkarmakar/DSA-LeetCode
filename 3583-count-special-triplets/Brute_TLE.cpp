class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){        
            for(int k=n-1;k>i;k--){

                if(nums[i]==nums[k]){

                    for(int j=i+1;j<k;j++){
                        if(2*nums[j]==nums[i]) count++;
                    }
                }
                
            }
        }
        
        return count;  
    }
};
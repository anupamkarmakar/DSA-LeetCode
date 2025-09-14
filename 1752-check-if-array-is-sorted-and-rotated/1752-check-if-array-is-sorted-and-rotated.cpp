class Solution {
public:
    bool check(vector<int>& nums) {
        // #Brute Force approch
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(nums[j]<=nums[j+1]) return true;
        //         else break;
        //     }
        //     int x=nums[n-1];
        //     for(int k=n-1;k<0;k--){
        //         nums[k]=nums[k-1];
        //     }
        //     nums[0]=x;
        // }
        // return false;

        int n=nums.size();
        //If there is only one element then it is absolutely true
        if(n==1) return 1;

        int pos=1;
        //step-1:Find the decearing pos of the cruve
        while(pos<n && nums[pos]>=nums[pos-1])
            pos++;
        
        if(pos==n) return true;  //there have only one cruve
        if(nums[pos]>nums[0]) return false;  //dec ele is greater than 1st ele
        if(pos==n-1) return true; //no other ele have after dec ele and smaller then nums[0]

        //step-2: check no dec order in 2nd curve
        pos+=1;
        while(pos<n && nums[pos]>=nums[pos-1] && nums[pos]<=nums[0])
            pos++;
        return pos==n;
    }
};
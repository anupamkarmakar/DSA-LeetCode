class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        const int mod = 1000000007;
        for(int i=0;i<n;i++){
            int mini=arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum=(sum+mini)%mod;
            }
        }
        return sum;
    }
};
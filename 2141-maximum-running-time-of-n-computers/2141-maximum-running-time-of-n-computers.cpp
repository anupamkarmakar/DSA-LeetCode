class Solution {
public:
    typedef long long ll;
    bool canrun(vector<int>&batteries, ll mid, int n){
        ll target=mid*n;
        ll sum=0;
        for(ll b : batteries){
            sum+=min(b,mid);
            if(sum>=target)
                return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum=0;
        ll ans=0;
        for(auto num : batteries) sum+=num;

        ll l=*min_element(begin(batteries),end(batteries));
        ll r=sum/n;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(canrun(batteries,mid,n)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
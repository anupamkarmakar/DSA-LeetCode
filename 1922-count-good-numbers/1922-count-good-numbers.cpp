class Solution {
public:
    #define ll long long    
    const ll mod = 1e9+7;

    ll power(ll x , ll n){
        if(n==0) return 1;
        x = x%mod;
        if(n%2==0) return power(x*x,n/2)%mod;
        else return power(x*x,(n-1)/2)*x%mod;
    }

    int countGoodNumbers(ll n) {
        ll evenNum =(n+1)/2;
        ll oddNum =n/2;

        ll digit = (power(5,evenNum)* power(4,oddNum))%mod;
        int ans = digit % mod;
        return ans;
    }
};
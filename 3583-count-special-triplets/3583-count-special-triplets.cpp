class Solution {
public:

    typedef long long ll;
    const int mod=1e9+7;

    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;

        unordered_map<ll,ll> right,left;

        // First fill the right map with frequency of all elements
        for(ll x : nums){
            right[x]++;
        }

        for(int j=0;j<n;++j){
            ll x= nums[j];
            ll t= 2*x; // need (t, x, t) pattern = (2x, x, 2x)

            // Move current element from right to "current" (i.e., no longer on right side)
            right[x]--;

            ll leftCount= left.count(t) ? left[t] : 0; 
            ll rightCount= right.count(t) ? right[t] : 0; 

            ll add= (leftCount * rightCount) % mod;

            ans=(ans+add)%mod;

            // Now x becomes part of the left side for future positions
            left[x]++;
        }
        return (int)ans;
    }
};

// Institution: https://chatgpt.com/share/6937f5ea-8150-8004-a55a-72a7eda160fc
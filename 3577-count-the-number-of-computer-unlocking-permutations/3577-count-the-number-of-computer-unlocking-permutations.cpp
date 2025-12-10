class Solution {
public:
    const int mod=1e9+7;
    long long factorial(int n){
        if(n==0 || n==1) return 1;
        return (factorial(n-1)*n)%mod;
    }
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();

        int x=complexity[0];
        for(int i=1;i<n;i++){
            if(x>=complexity[i]) return 0;
        }
        
        long long fact = factorial(n-1)%mod;
        return (int)fact;
    }
};
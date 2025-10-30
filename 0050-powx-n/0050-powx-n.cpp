class Solution {
public:
    double myPow(double x, int N) {
        long long n=N;
        if(n<0) n=-n,x=1/x;
        // Base Case
        if(n==0) return 1;

        if(n%2==0) return myPow(x*x,n/2); //if power is even 
        else return myPow(x*x,(n-1)/2)*x; //if odd
    }
};
class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0; //prime has size 0,prime[0] and prime[1] are out of bounds,This causes runtime error / segmentation fault
        
        vector<bool>prime(n,true);
        prime[0]=prime[1]=false;

        for(int i=2; i*i<n; i++){
            if(prime[i]==true){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        
        int count = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]) count++;
        }
        return count;
    }
};
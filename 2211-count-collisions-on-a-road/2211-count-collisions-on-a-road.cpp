class Solution {
public:
    int countCollisions(string D) {
        int n=D.size();
        if(n<=1) return 0;
        
        int count=0;
        int l=0,r=n-1;

        while(l<n && D[l]=='L') l++;
        while(r>l && D[r]=='R') r--;

        if(l==r) return 0;

        for(int i=l;i<=r;i++){
            if(D[i]=='L' || D[i]=='R') count++;
        }
        return count;
    }
};
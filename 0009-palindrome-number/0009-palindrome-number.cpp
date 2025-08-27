class Solution {
public:
    bool isPalindrome(int x) {
        int act=x,ld;
        long long rev=0;
        while(x>0){
            ld=x%10;
            rev=rev*10+ld;
            x/=10;
        }
        if(rev==act) return true;
        else return false;
    }
};
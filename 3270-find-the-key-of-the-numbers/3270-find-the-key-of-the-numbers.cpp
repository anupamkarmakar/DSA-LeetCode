class Solution {
public:
    int generateKey(int num1, int num2, int num3) {

        int ans=0,ld;
        int place = 1;
        for(int i=0;i<=3;i++){
            ld = min((num1 % 10), min((num2 % 10), (num3 % 10)));
            // Rev ans = ans*10 + ld
            ans += ld*place;
            place *= 10;
            
            num1/=10;
            num2/=10;
            num3/=10;
        }
        return ans;
    }
};
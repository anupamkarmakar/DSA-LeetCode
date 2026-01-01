class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;

        for(int i=n-1;i>=0;i--){
            int ld=digits[i]+carry;
            digits[i]=ld%10;  //if ld=10, then digits[i]=0;
            carry=ld/10; //if ld=10, then carry=1, if<10 carry=0;

            if(carry==0) break; //Not need to go further
        }

        if(carry) digits.insert(digits.begin(),1); // add first position, ex=999

        return digits;
    }
};
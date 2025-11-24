class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int decimal=0;

        for(int bit : nums){
            // decimal=(decimal*2+bit) Find decimal number, it happens overflow
            decimal=(decimal*2+bit)%10; // so we use modulo
            ans.push_back(decimal%5==0);
        }
        return ans;
    }
};
class Solution {
public:
    long long solve(string s, int i, long long num, int sign){
        // Base case: end or non-digit
        if(i>s.size() || !isdigit(s[i])){
            return num*sign;
        }

        num = num*10 + s[i]-'0';

        // Overflow handeling
        if(sign==1 && sign*num>INT_MAX) return INT_MAX;
        if(sign==-1 && sign*num<INT_MIN) return INT_MIN;

        return solve(s,i+1,num,sign);
    }

    int myAtoi(string s) {
        int n=s.size();
        int i=0,sign=1;

        // Skip leading space
        while(i<n && s[i]==' ') i++;

        // Sign
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign= (s[i]=='-')? -1 : 1;
            i++;
        }

        // Resursive slove
        return (int)solve(s,i,0,sign);
    }
};
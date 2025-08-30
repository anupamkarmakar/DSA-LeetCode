class Solution {
public:
    bool isPalindrome(string s) {
        int i;
        int j=0;
        for(i=0;i<s.size();i++){
            if(isalnum(s[i])){
                s[j++]=tolower(s[i]);
            }
        }
        s.resize(j);
        for(j=0,i=s.size()-1;j<i;j++,i--){
            if(s[j]!=s[i]){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;
        string result;

    for(int i=0;i<s.size();i++){
        if(s[i]==')') counter--;
        if(counter>0) result+=s[i];
        if(s[i]=='(') counter++;
    }
    return result;
    }
};
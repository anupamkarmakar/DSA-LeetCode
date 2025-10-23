class Solution {
public:
    int maxDepth(string s) {
        int counter=0,mx=0;
        for(int i=0;i<s.size();i++){
            mx=max(mx,counter);
            if(s[i]=='(') counter++;
            else if(s[i]==')') counter--;
        }
        return mx;
    }
};
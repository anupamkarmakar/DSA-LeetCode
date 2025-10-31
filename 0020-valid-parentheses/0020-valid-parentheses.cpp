class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(char x : s){
            if(x=='(' || x=='{' || x=='[') st.push(x);
            else{
                if(st.empty()) return false;

                char top=st.top();
                if((x==')' && top=='(') || (x=='}' && top=='{') || (x==']' && top=='[')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        if(st.empty()) return true;
        return false;
    }
};
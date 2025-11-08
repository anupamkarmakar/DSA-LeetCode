class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;

        // Remove significant digits
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }

        // Remove if remains items
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        if(st.empty()) return "0";

        // Elements is stored reversely
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        // Remove leading zeros
        while(!res.empty() && res.back()=='0') res.pop_back();
        reverse(res.begin(),res.end()); //reverse it

        // if all elements is removed
        if(res.empty()) return "0";
        return res;
    }
};
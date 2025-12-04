class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int count=0;

        for(char ch : directions){
            // Handle when an 'L' meets 'R' cars on stack
            while(!st.empty() && st.top()=='R' && ch=='L'){
                count+=2;
                st.pop();
                ch='S';
            }
            while(!st.empty() && st.top()=='R' && ch=='S'){
                count++;
                st.pop();
                ch='S';
            }
            if(!st.empty() && st.top()=='S' && ch=='L'){
                count++;
                ch='S';
            }
            st.push(ch);
        }
        return count;
    }
};
class Solution {
public:
    #define ll long long
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        vector<int> nse(n),pse(n);
        stack<int> st;

        // Find nse, we store idx of it
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i]=st.empty()  ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Find pse, we store idx of it
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            pse[i]=st.empty()  ? -1 : st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1ll*arr[i])%mod)%mod;
        }
        return total;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector <int> hash(256,0);
        for(char ch : t) hash[ch]++;

        int minlen = INT_MAX, startIdx = -1, count = 0;
        int l=0, r=0;

        while(r<n){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;

            while(count==m){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    startIdx = l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        if(startIdx==-1) return "";
        return s.substr(startIdx,minlen);
    }
};
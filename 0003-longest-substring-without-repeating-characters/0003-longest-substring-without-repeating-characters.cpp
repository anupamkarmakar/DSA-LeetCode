class Solution {
public:
    // using set
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set <char> charset;
        int left=0;
        int maxlen=0;
        for(int right=0;right<n;right++){
            if(charset.count(s[right])==0){
                charset.insert(s[right]);
                maxlen=max(maxlen,right-left+1);
            }else{
                while(charset.count(s[right])){
                    charset.erase(s[left]);
                    left++;
                }
                charset.insert(s[right]);
            }
        }
        return maxlen;
    }
};
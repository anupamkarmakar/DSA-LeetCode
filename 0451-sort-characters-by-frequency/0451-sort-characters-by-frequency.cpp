class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> freq;
        for(char ch:s){
            freq[ch]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b) { //lamda function
            if (freq[a] != freq[b])
                return freq[a] > freq[b];  // higher frequency first
            return a < b;                  // tie-breaker (optional)
        });
        
        return s;
    }
};
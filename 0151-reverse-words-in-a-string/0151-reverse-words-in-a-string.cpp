class Solution {
public:
    string reverseWords(string s) {
        string word,result;
        if (s.empty()) return "";

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ') word+=s[i];
            
            // add word by word
            else if(!word.empty()){
                reverse(word.begin(),word.end());
                result+=word+" ";
                word.clear();
            }
        }

        // add last word
        if(!word.empty()){
            reverse(word.begin(),word.end());
                result+=word;
                word.clear();
        }

        //revome trailing space
        if(!result.empty() && result.back()==' ') result.pop_back();

        return result;
    }
};
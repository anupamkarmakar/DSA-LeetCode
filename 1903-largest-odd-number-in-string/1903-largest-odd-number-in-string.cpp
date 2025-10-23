class Solution {
public:
    string largestOddNumber(string num) {

        // travel from last digit to first
        for(int i=num.size()-1;i>=0;i--){

            // check odd
            if((num[i]-'0')%2!=0){ //suppose num[i]='7'=55 (ASCII VALUE); '7'-'0'=55-48= 7 <-int
                return num.substr(0,i+1); // substr(start index,number of char(length)) 
            }
        }

        // if there are no odd number
        return "";
    }
};
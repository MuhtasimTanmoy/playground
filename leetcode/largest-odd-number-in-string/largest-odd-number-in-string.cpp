class Solution {
public:
    string largestOddNumber(string num) {
        
        for(int i = size(num) - 1; i >= 0 ; i-- ) 
            if ((num[i] - '0') & 1) return num.substr(0, i + 1);
        return "";
    }
};
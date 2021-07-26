class Solution {
public:
    int lengthOfLastWord(string s) {
                
        int length = s.size() - 1;
        
        int result = 0;
        
        while(length >= 0 && s[length] == ' ') {
            length--;
        }
        
        while( length >= 0 &&  s[length] != ' ') {
            result++;
            length--;
        }
        
        return result;
    }
};
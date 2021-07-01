class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char target = s[0];
        target^=s[0];
        
        for(char c: s){
            target^=c;
        }
        
        for(char c: t){
            target^=c;
        }
        
        return target;
    }
};
class Solution {
public:
    int numDifferentIntegers(string word) {
        
        auto isChar = [](char c) {
            return c >= 'a' && c <= 'z';
        };
        
        unordered_set<string> bag;
        
        for( int i = 0; i < size(word); ) {
            
            if( isChar(word[i]) ) {
                i++;
            } else {
                string number = "";            
                while(word[i] == '0') i++;
                while(word[i] >= '0' && word[i] <= '9') number += word[i++];           
                bag.insert(number);
            }
        }
        
        return size(bag);
    }
};
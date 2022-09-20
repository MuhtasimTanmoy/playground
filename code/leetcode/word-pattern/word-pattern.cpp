class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s += " ";

        vector<string> tokens;
        int startIndex = 0;
        
        for(int i = 0; i < s.size(); i++ ) {
            if ( s[i] == ' ' ) {
                tokens.push_back(s.substr(startIndex, i - startIndex));
                startIndex = i + 1;
            }
        }
        
        if ( pattern.size() != tokens.size() ) { return false; }
        
        map<char, string> charMap;
        map<string, char> strMap;
                
        for(int i = 0; i < pattern.size(); i++) {
            
            if ( charMap.count(pattern[i]) == 0 && strMap.count(tokens[i]) == 0) {
                
                charMap[pattern[i]] = tokens[i];
                strMap[tokens[i]] = pattern[i];
            }
            
            if ( tokens[i] != charMap[pattern[i]] ) {
                return false;
            }
        }
        
        return true;
    }
};
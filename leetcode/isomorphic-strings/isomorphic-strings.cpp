class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if ( s.size() != t.size() ) { return false; }
        
        unordered_map<char,char> charMap;
        unordered_set<char> bag;
        
        for( int i = 0; i < s.size(); i++) {
            if ( charMap.count(s[i]) == 0 ) {
                if ( bag.count(t[i]) ) { return false; }
                charMap[s[i]] = t[i];
                bag.insert(t[i]);
            }
        }
        
        for( int i = 0; i < s.size(); i++) {
            if ( charMap[s[i]] != t[i] ) {
                return false;
            }
        }
        
        return true;
    }
};
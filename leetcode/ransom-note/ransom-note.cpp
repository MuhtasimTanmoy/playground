class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> chars(26);
        
        for( char c : magazine ) {
            chars[ c - 'a' ] += 1;
        }
        
        for( char c : ransomNote ) {
            chars[ c - 'a' ] -= 1;
        }
        
        for ( auto indexCount : chars) {
            if ( indexCount < 0) {
                return false;
            }
        }
        
        return true;
    }
};
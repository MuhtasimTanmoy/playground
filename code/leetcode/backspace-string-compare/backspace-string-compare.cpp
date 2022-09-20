class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> _s;
        for( int i = 0; i < size(s); i++ ) {
            if( s[i] == '#') { if (!_s.empty()) _s.pop(); }
            else _s.push(s[i]);
        }
        
        stack<char> _t;
        for( int i = 0; i < size(t); i++ ) {
            if( t[i] == '#' ) { if (!_t.empty()) _t.pop(); }
            else _t.push(t[i]);
        }
        
        
        if ( size(_s) != size(_t) ) return false; 
        
        while ( !_s.empty() ) {
            if( _s.top() != _t.top() ) return false; 
            _s.pop();
            _t.pop();
        }
        
        return true;
    }
};
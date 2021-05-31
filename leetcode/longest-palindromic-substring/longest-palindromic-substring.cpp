class Solution {
public:
    string longestPalindrome(string s) {
       int length = s.length();
        int long_pal = 0;
        int start = 0;
        auto getlength = [&] ( int l, int r){
            while (  l >= 0 && r < length && s[l] == s[r]  ){
                -- l;
                ++ r;
            }
            return r -l - 1;
        };
        for ( int i = 0; i < length; i++ ){
            int cur_pal = max( getlength(i, i), getlength(i, i+1) );
            if ( cur_pal > long_pal){
                long_pal = cur_pal;
                start = i - (long_pal -1) /2;
            }
        }
        return s.substr( start , long_pal);
    }
};
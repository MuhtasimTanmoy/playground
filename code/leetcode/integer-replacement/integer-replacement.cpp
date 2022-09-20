class Solution {
    public:
    int integerReplacement(int n) {
        if ( n == 1) return 0;
        if ( n == INT_MAX ) return 32;

        if ( n & 1 ) {
            return 1 + min(integerReplacement(n-1), 
                           integerReplacement(n+1));
        }
        
        n = n >> 1;
        return 1 + integerReplacement(n);
    }
};
class Solution {
public:
    
    unordered_map<int, int> bag;
    
    int climbStairs(int n) {
        
        if ( n < 0 ) { return 0; }
        
        if ( n == 0 ) {
            return 1;
        }
        
        if ( bag.count(n) ) {
            return bag[n];
        }
        bag[n] = climbStairs(n-1) + climbStairs(n-2);
        return bag[n];
    }
};
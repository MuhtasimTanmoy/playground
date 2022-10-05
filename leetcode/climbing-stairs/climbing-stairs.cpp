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

//--- method 1: dp iteration
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp.back();
    }
};

//--- method 2: O(1) space
class Solution {
public:
    int climbStairs(int n) {
        int last1 = 1, last2 = 1;
        for (int i = 2; i <= n; ++i) {
            auto tmp = last1+last2;
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
};
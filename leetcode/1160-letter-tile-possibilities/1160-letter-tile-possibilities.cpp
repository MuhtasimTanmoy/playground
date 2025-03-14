class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> dp(26, 0);
        for (auto c: tiles) dp[c - 'A']++;
        
        int res = 0;
        function<void()> go = [&]() {
           for (auto i = 0; i < 26; i++) 
               if (dp[i]) 
                   dp[i]--,
                   res++,
                   go(),
                   dp[i]++;
        };
        go();
        return res;
    }
};
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        auto check = [](vector<int>& counter) {
            int now = -1;
            for (auto c: counter) 
                if (c) {
                    if (now == -1) now = c;
                    else if (now != c) return false;
                }
            return true;
        };
        
        vector<int> dp(1001, -1);
        int n = s.size();
        function<int(int)> go = [&](auto i) {
            if (i == n) return 0;
            if (dp[i] != -1) return dp[i];
            
            vector<int> tracker(26, 0);
            int ans = n;
            
            for (auto j = i; j < n; j++) {
                tracker[s[j] - 'a']++;
                if (check(tracker)) ans = min(ans, 1 + go(j + 1));
            }
            return dp[i] = ans;
        };
        return go(0);
    }
};


// class Solution {
// public:
//     bool chk(map<int,int> &mp) {
        
//         auto firstElement = mp.begin();
//         int freq = firstElement->second;
        
//         for(auto &[ele, f]: mp)
//             if(f != freq) return false;
//         return true;
//     }
    
//     int dp[1001];
//     int f(int i, string &s){
//         int n = s.size();
//         if(i==n) return 0;
        
//         if(dp[i]!= -1) return dp[i];
//         int ans = n;
        
//         map<int,int> mp;
//         for(int j=i; j<n; j++) {
//             mp[s[j]]++;
//             if (chk(mp)) ans = min(ans, 1 + f(j+1, s));
//         }
        
//         return dp[i] = ans;
//     }
    
//     int minimumSubstringsInPartition(string s) {
//         memset(dp, -1, sizeof(dp));
//         return f(0, s);
//     }
// };
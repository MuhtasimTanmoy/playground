// class Solution {
// public:
//     int minStickers(vector<string>& stickers, string target) {
        
//         int n = stickers.size();
//         vector<int, vector<int>> counter(n, new vector<int>(26, 0));
//         for (auto i = 0; i < n; i++) 
//             for (auto c: counter[i]) 
//                 counter[i][c-'a']++;
        
//         vector<int> need(26, 0);
//         for (auto c: target) need[c-'a']++;
        
//         auto is_done = [&need]() {
//             for (auto num: need) if (need > 1) return false;
//             return true;
//         };
        
//         auto increment = [&](int i) {
//             for (auto c: counter[i]) need[c-'a']++;
//         };
        
//         auto decrement = [&](int i) {
//             for (auto c: counter[i]) need[c-'a']--;
//         };
        
//         int res = INT_MAX;
//         function<void(int)> go = [&](int count) {
//             if (is_done()) {
//                 res = min(res, count);
//                 return;
//             }
            
//             for (auto i = 0; i < n; i++) {
                
//             }
//         };
        
//         go();
//     }
// };

class Solution {
    int memo[32768];
public:
    int dp(int mask, string& target, vector<vector<int>>& arr, int allmask) {
        if (mask == allmask) return 0;
        else if (memo[mask]) return memo[mask];
        else {
            int q = 51;
            for(vector<int> word :arr) {
                int newMask = mask;
                for (int i = 0; i < target.length(); ++i)
                    if ((mask & 1 << i) == 0 && word[target[i]-'a'])
                        newMask |= 1<<i,
                        word[target[i]-'a']--;
                if (newMask != mask)
                    q = min(q, 1 + dp(newMask, target, arr, allmask));
            }
            return memo[mask]=q;
        }
    }
    
    int minStickers(vector<string>& stickers, string target)  {
        vector<vector<int>> arr(stickers.size());
        memset(memo, 0, sizeof(memo));
        for (int i = 0; i < stickers.size(); ++i) {
            vector<int> c(26, 0);
            for (char a :stickers[i]) c[a-'a']++;
            arr[i] = c;
        }
        int allmask = (1 << target.length()) - 1;
        int val = dp(0, target, arr, allmask);
        return val < 51 ? val : -1;
    }
};
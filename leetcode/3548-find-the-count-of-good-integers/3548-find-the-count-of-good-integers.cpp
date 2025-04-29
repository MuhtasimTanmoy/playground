// class Solution {
// public:
//     long long countGoodIntegers(int n, int k) {
//         string start = "1" + string(n - 1, '0');
//         auto is_palin = [](string& s) {
//             int l = (s.size() + 1) / 2, r = l;
//             while (l >= 0 && r < s.size())
//                 if (s[l--] != s[r++])
//                     return false;
//             return true;
//         };
//         int m = start.size(), res = 0;
//         while (start.size() == m) {
//             auto i = stoi(start);
//             cout<<i<<endl;
//             if (((i % k) == 0) && is_palin(start)) res++;
//             start = to_string(++i);
//         }
//         return res;
//     }
// };

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        for (int i = base; i < base * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palindromicInteger = stoll(s);
            if (palindromicInteger % k == 0) 
                sort(s.begin(), s.end()),
                dict.emplace(s);
        }
        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++) 
            factorial[i] = factorial[i - 1] * i;
        for (const string &s : dict) {
            vector<int> cnt(10);
            for (char c : s) cnt[c - '0']++;
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for (int x : cnt) tot /= factorial[x];
            ans += tot;
        }
        return ans;
    }
};
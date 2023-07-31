class Solution {
public:
//     int minimumBeautifulSubstrings(string s) {
//         unordered_set<int> bag{ 1, 5, 25, 125, 625, 3125, 15625 };
        
//         unordered_set<string> bag;
//         auto trim = [](string& a) -> string {
//             int i = 0;
//             while (a[i] == '0') i++;
//             return a.substr(i);
//         };
        
//         for (long long i = 0; i < 22; i++) {
//             auto num = bitset<16>(pow(5, i)).to_string();
//             bag.insert(trim(num));
//         }
        
//         for (auto c: bag)
//             cout<<c<<endl;
        
//         int res = INT_MAX;
//         function<void(string, int)> go = [&](auto st, int cnt) {
//             if (st.size() == 0) {
//                 res = min(res, cnt);
//                 return;
//             }
//             string temp = st;
//             while (temp.size()) {
//                 if (bag.count(temp)) {
//                     cout<<temp<<endl;
//                     go(st.substr(temp.size()), cnt + 1);
//                 }
//                 temp.pop_back();
//             }
//         };       
        
//         go(s, 0);
//         return res == INT_MAX ? -1: res;
//     }
    
    unordered_set<int> p5{ 1, 5, 25, 125, 625, 3125, 15625 };
    
    int dfs(int i, int val, const string &s) {
        if (i == s.size())
            return val == 0 ? 0 : 16;
        val = val * 2 + (s[i] -'0');
        if (val == 0)
            return s.size() + 1;
        return min(dfs(i + 1, val, s), 1 + 
                   (p5.count(val) ? dfs(i + 1, 0, s) : (int)s.size()));
    }
    
    int minimumBeautifulSubstrings(const string & s) {
        int res = dfs(0, 0, s);
        return res > s.size() ? -1 : res;
    }
};
class Solution {
public:
//     bool canBeValid(string s, string locked) {
//         unordered_map<string, int> dp;
//         auto gen_key = [](auto i, auto j) {
//             return to_string(i) + "-" + to_string(j);
//         };
        
//         function<bool(int, int)> go = [&](auto i, auto pending) -> int {
//             if (i == s.size() || pending < 0) return pending == 0;
//             if (locked[i] == '1' && !pending && s[i] == ')') return false;
            
//             auto key = gen_key(i, pending);
//             if (dp.count(key)) return dp[key];
            
//             auto res = false;
//             if (locked[i] == '1')
//                 if (s[i] == '(') res |= go(i + 1, pending + 1);
//                 else res |= go(i + 1, pending - 1);
//             else {
//                 res |= go(i + 1, pending + 1);
//                 res |= go(i + 1, pending - 1);
//             }
//             return dp[key] = res;
//         };
//         return go(0, 0);
//     }
    
    bool canBeValid(string s, string locked) {
        auto validate = [&](char op) {
            int bal = 0, wild = 0, sz = s.size();
            int start = op == '(' ? 0 : sz - 1, dir = op == '(' ? 1 : - 1;
            for (int i = start; i >= 0 && i < sz && wild + bal >= 0; i += dir)
                if (locked[i] == '1')
                    bal += s[i] == op ? 1 : -1;
                else
                    ++wild;
            return abs(bal) <= wild;
        };
        return s.size() % 2 == 0 && validate('(') && validate(')');
    }
};
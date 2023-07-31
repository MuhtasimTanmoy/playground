class Solution { 
public:
//     int maxValue(vector<vector<int>>& events, int k) {
//         int n = events.size();
//         sort(events.begin(), events.end(), [](auto &a, auto &b) {
//             return a[1] < b[1];
//         });
//         unordered_set<string> um;
//         auto gen_key = [](auto l, auto ...r) {
//            return (to_string(l) + ... + ("-" + to_string(r)));
//         };
//         int res = 0;
//         function<void(int, int, int, int)> go = [&](auto i, auto last, auto val, auto left) {
//             if (i == n || !left) {
//                 res = max(res, val);
//                 return;
//             }
//             auto key = gen_key(i, last, val, left);
//             if (um.count(key)) return;
            
//             auto from = events[i][0], to = events[i][1], weight = events[i][2];
//             if (last < from)
//                 go(i + 1, to, val + weight, left - 1);
//             go(i + 1, last, val, left);
//             um.insert(key);
//         };
//         go(0, 0, 0, k);
//         return res;
//     }
    
    
      int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
          
        unordered_map<string, int> um;
        auto gen_key = [](auto l, auto ...r) {
           return (to_string(l) + ... + ("-" + to_string(r)));
        };
          
        function<int(int, int, int)> go = [&](auto i, auto last, auto left) -> int {
            if (i == n || !left) return 0;
            auto key = gen_key(i, last, left);
            if (um.count(key)) return um[key];
            
            auto from = events[i][0], to = events[i][1], weight = events[i][2];
            auto calc = go(i + 1, last, left);
            
            if (last < from) {
                auto with = weight + go(i + 1, to, left - 1);
                calc = max(calc, with);
            }
            return um[key] = calc;
        };
        auto res = go(0, 0, k);
        return res;
    }
};
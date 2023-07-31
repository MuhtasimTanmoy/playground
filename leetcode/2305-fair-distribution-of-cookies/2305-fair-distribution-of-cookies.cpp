// First attempt
// [1,1,2,2,2,3,4,6]
// 3

// class Solution {
// public:
//     int distributeCookies(vector<int>& cookies, int k) {
//         vector<int> distributor(k, 0);
//         function<int(int, int)> go = [&](auto i, auto so_far_max) {
//             if (i == cookies.size()) return so_far_max;
//             int res = INT_MAX;
//             for (auto &d: distributor) 
//                 d += cookies[i],
//                 res = min(res, go(i + 1, max(so_far_max, d))),
//                 d -= cookies[i];
//             return res;
//         };
//         return go(0, 0);
//     }
// };

// class Solution {
// public:
//     int distributeCookies(vector<int>& cookies, int k) {
//         unordered_map<string, int> cache;
//         auto gen_key = [](int a, int b) {
//             return to_string(a) + "-" + to_string(b);
//         };
//         vector<int> distributor(k, 0);
//         function<int(int, int)> go = [&](auto i, auto so_far_max) {
//             if (i == cookies.size()) return so_far_max;    
//             auto key = gen_key(i, so_far_max);
//             if (cache.count(key)) return cache[key];     
//             int res = INT_MAX;
//             for (auto &d: distributor) 
//                 d += cookies[i],
//                 res = min(res, go(i + 1, max(so_far_max, d))),
//                 d -= cookies[i];
//             return cache[key] = res;
//         };
//         return go(0, 0);
//     }
// };

// class Solution {
// public:
//     int distributeCookies(vector<int>& cookies, int k) {
//         unordered_map<int, int> cache;
//         vector<int> distributor(k, 0);
//         function<int(int)> go = [&](auto i) {
//             if (i == cookies.size()) 
//                 return *max_element(distributor.begin(), distributor.end());
//             int res = INT_MAX;
//             for (auto &d: distributor) 
//                 d += cookies[i],
//                 res = min(res, go(i + 1)),
//                 d -= cookies[i];
//             return res;
//         };
//         return go(0);
//     }
// };

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distributor(k, 0);
        function<int(int, int)> go = [&](auto i, auto so_far_max) {
            if (i == cookies.size()) return so_far_max;
            int res = INT_MAX;
            for (auto &d: distributor) 
                d += cookies[i],
                res = min(res, go(i + 1, max(so_far_max, d))),
                d -= cookies[i];
            return res;
        };
        return go(0, 0);
    }
};

// class Solution {
// public:
//     int maxNonDecreasingLength(vector<int>& l, vector<int>& r) {
//         int n = l.size();
//         vector<int> res(n, 0); res[0] = min(l[0], r[0]);
//         for (int i = 1; i < n; i++) {
//             auto min_elem = min(l[i], r[i]), max_elem = max(l[i], r[i]);
//             res[i] = min_elem >= res[i - 1] ? min_elem: max_elem;
//         }
//         int ans = 1;
//         for (int i = 1, counting = 1; i < n; i++) {
//             cout<<res[i]<<endl;
//             if (res[i] >= res[i-1]) counting++; else counting = 1;
//             ans = max(ans, counting);
//         }
//         return ans;
//     }
// };



// 2922 / 2973 test cases passed.
/*
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& l, vector<int>& r) {
        int res = 0, n = l.size();
        
        unordered_set<string> c;
        auto gen_key = [](int a, int b, int c) {
            return to_string(a) + "-" + to_string(b) + "-" + to_string(c);
        };
        
        function<void(int, int, int)> go = [&](auto i, auto prev, auto cnt) {
            res = max(res, cnt);
            if (i == n) return;
            
            auto key = gen_key(i, prev, cnt);
            if (c.count(key)) return;
            
            go(i + 1, l[i], l[i] >= prev ? cnt + 1: 1);
            go(i + 1, r[i], r[i] >= prev ? cnt + 1: 1);
            
            c.insert(key);
        };
        
        go(1, min(l[0], r[0]), 1);
        return res;
    }
};
*/


class Solution {
public:
    int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
        int res = 1, dp1 = 1, dp2 = 1, n = A.size(), t11, t12, t21, t22;
        for (int i = 1; i < n; ++i) {
            t11 =  A[i - 1] <= A[i] ? dp1 + 1 : 1;
            t12 = A[i - 1] <= B[i] ? dp1 + 1 : 1;
            t21 = B[i - 1] <= A[i] ? dp2 + 1 : 1;
            t22 = B[i - 1] <= B[i] ? dp2 + 1 : 1;
            dp1 = max(t11, t21);
            dp2 = max(t12, t22);
            res = max(res, max(dp1, dp2));
        }
        return res;
    }
};
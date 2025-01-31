// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& N) {
//         long long res = N.size(), n = N.size();
//         for (auto i = 0; i < n - 1; i++)
//             for (auto j = i + 1, min_elem = N[i], max_elem = N[i]; j < n; j++) {
//                 min_elem = min(min_elem, N[j]);
//                 max_elem = max(max_elem, N[j]);
//                 if (max_elem - min_elem <= 2) res++;
//             }
//         return res;
//     }
// };

class Solution {
public:
    long long continuousSubarrays(vector<int>& N) {
        long long res = 0;
        map<int, int> t;
        for (int l = 0, r = 0; r < N.size(); r++) {
            t[N[r]]++;            
            while ( t.size() && (t.rbegin()->first - t.begin()->first) > 2 ) {
                if (--t[N[l]] == 0) t.erase(N[l]);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};
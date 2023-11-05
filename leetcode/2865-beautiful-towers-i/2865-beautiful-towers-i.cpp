class Solution {
public:
//     long long maximumSumOfHeights(vector<int>& h) {
//         auto max_elem = *max_element(h.begin(), h.end());
        
//         vector<int> idx;
//         for (int i = 0; i < h.size(); i++)
//             if (h[i] == max_elem)
//                 if (idx.empty() || (i - idx.back()) > 1)
//                     idx.push_back(i);
                
//         long long res = 0;
//         for (auto from: idx) {
//             long long sum = 0;
//             for (auto i = from + 1, min_so_far = INT_MAX; i < h.size(); i++) 
//                 min_so_far = min(min_so_far, h[i]),
//                 sum += min_so_far;
//             for (auto i = from, min_so_far = INT_MAX; i >= 0; i--) 
//                 min_so_far = min(min_so_far, h[i]),
//                 sum += min_so_far;
//             res = max(sum, res);
//         }
//         return res;
//     }
    
    #define ll long long
    long long maximumSumOfHeights(vector<int>& a) {
        int n = a.size();
        ll int ans = 0;
        for (int i = 0; i < n; i++) {
            ll int sum = a[i];
            int prev = a[i];
            for (int j = i - 1; j >= 0; j--) 
                prev = min(a[j],prev),
                sum += prev;
            prev = a[i];
            for (int j = i + 1; j < n; j++) 
                prev = min(a[j],prev),
                sum += prev;
            if (sum > ans) ans = sum;
        }
        return ans;
    }
};
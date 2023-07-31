// Will work in case of 
// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int res = INT_MAX;
//         for (int l = 0, r = 0, sum = 0; r < nums.size(); r++) {
//             sum += nums[r];
//             while (sum >= k && l <= r) 
//                 res = min(res, r - l + 1),
//                 sum -= nums[l++];
//         }
//         return res == INT_MAX ? -1: res;
//     }
// };

class Solution {
public:
    int shortestSubarray(vector<int> B, int K) {
        int N = B.size(), res = N + 1; deque<long> d;
        vector<long long> A(B.begin(), B.end());
        for (int i = 0; i < N; i++) {
            if (i) A[i] += A[i - 1];
            if (A[i] >= K) res = min(res, i + 1);
            while (d.size() && A[i] - A[d.front()] >= K)
                res = min(res, i - (int) d.front()), d.pop_front();
            while (d.size() && A[i] <= A[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};
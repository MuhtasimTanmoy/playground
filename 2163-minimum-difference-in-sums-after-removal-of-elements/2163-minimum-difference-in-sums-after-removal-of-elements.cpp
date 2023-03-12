class Solution {
public:
    long long minimumDifference(vector<int>& A) {
        priority_queue<int> L;
        priority_queue<int,vector<int>, greater<>> R;
        long N = A.size() / 3, left = 0, right = 0, ans = LLONG_MAX;
        vector<long> tmp(A.size());
        
        for (int i = A.size() - 1; i >= N; --i) {
            R.push(A[i]);
            right += A[i];
            if (R.size() > N) {
                right -= R.top();
                R.pop();
            }
            if (R.size() == N) tmp[i] = right;
        }
        
        for (int i = 0; i < A.size() - N; ++i) {
            L.push(A[i]);
            left += A[i];
            if (L.size() > N) {
                left -= L.top();
                L.pop();
            }
            if (L.size() == N) ans = min(ans, left - tmp[i + 1]);
        }
        return ans;
    }
};
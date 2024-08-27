class Solution {
public:
    // int minKBitFlips(vector<int>& N, int k) {
    //     int res = 0, skip_if = 1, skip_upto = -1;
    //     for (auto i = 0; i < N.size(); i++) {
    //         if (i == skip_upto) skip_if = 1 - skip_if;
    //         if (N[i] == skip_if) continue;
    //         res++;
    //         skip_if = 1 - skip_if;
    //         skip_upto = i + k - 1;
    //         cout<<skip_upto<<endl;
    //         if (skip_upto >= N.size()) return -1;
    //     }
    //     return res;
    // }
    
    // int minKBitFlips(vector<int>& A, int K, int res = 0) {
    //   for (auto i = 0; i < A.size(); ++i) {
    //     if (A[i] != 1) {
    //       if (i + K - 1 >= A.size()) return -1;
    //       for (auto j = i; j < i + K; ++j) A[j] = !A[j];
    //       ++res;
    //     }
    //   }
    //   return res;
    // }
    
    int minKBitFlips(vector<int>& A, int K, int res = 0) {
      queue<int> flips;
      for (auto i = 0; i < A.size(); ++i) {
        if (A[i] != (flips.size() % 2 ? 0 : 1)) 
          ++res,
          flips.push(i + K - 1);
        if (flips.size() && flips.front() <= i) flips.pop();
      }
      return flips.empty() ? res : -1;
    }
};
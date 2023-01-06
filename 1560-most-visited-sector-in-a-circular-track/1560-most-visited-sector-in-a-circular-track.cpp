class Solution {
public:
    // vector<int> mostVisited(int n, vector<int>& rounds) {
    //     vector<int> res(n, 0);
    //     res[rounds[0] - 1]++;
    //     for (int i = 1; i < rounds.size(); i++) {
    //         auto start = rounds[i-1], end = rounds[i] - 1;
    //         while (start != end) {
    //             start = ++start % n;
    //             res[start]++;
    //         }
    //         res[end]++;
    //     }
    //     vector<int> maxRes; int maxScore = INT_MIN;
    //     for (int i = 0; i < res.size(); i++) {
    //         cout<<res[i]<<endl;
    //         if (res[i] >= maxScore) {
    //             if (res[i] > maxScore) maxRes.clear();
    //             maxScore = res[i];
    //             maxRes.push_back(i + 1);
    //         } 
    //     }
    //     return maxRes;
    // }
    vector<int> mostVisited(int n, vector<int>& A) {
        vector<int> res;
        for (int i = A[0]; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        if (res.size() > 0) return res;
        for (int i = 1; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        for (int i = A[0]; i <= n; ++i)
            res.push_back(i);
        return res;
    }
};
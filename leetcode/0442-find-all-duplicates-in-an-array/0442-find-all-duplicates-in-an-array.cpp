class Solution {
public:
    vector<int> findDuplicates(vector<int>& N) {
        vector<int> res;
        for (auto i = 0; i < N.size(); i++) {
            auto idx = abs(N[i]) - 1;
            if (N[idx] < 0) res.push_back(idx + 1);
            N[idx] = -(abs(N[idx]));
        }
        return res;
    }
};
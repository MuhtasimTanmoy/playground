class Solution {
public:
    vector<int> minCosts(vector<int>& C) {
        for (auto i = 0, min_so_far = INT_MAX; i < C.size(); i++) 
            min_so_far = min(min_so_far, C[i]),
            C[i] = min_so_far;
        return C;
    }
};
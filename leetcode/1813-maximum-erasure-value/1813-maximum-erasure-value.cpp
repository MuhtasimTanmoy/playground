class Solution {
public:
    int maximumUniqueSubarray(vector<int>& N) {
        unordered_set<int> bag;
        int res = 0;
        for (auto l = 0, r = 0, sum = 0; r < N.size(); r++) {
            while (bag.count(N[r])) 
                sum -= N[l],
                bag.erase(N[l++]);
            sum += N[r];
            bag.insert(N[r]);
            res = max(res, sum);
        }
        return res;
    }
};
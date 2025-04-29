class Solution {
public:
    int countCompleteSubarrays(vector<int>& N) {
        auto distinct_count = unordered_set<int>(N.begin(), N.end()).size();

        unordered_map<int, int> counter;
        int res = 0;
        for (auto l = 0, r = 0; r < N.size(); r++) {
            counter[N[r]]++;
            while (counter.size() == distinct_count) {
                res += N.size() - r;
                if (--counter[N[l]] == 0) counter.erase(N[l]);
                l++;
            }
        }
        return res;
    }
};
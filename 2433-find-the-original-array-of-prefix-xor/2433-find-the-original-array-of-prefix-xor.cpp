class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for (auto i = pref.size() - 1; i > 0; i--) pref[i] ^= pref[i-1];
        return pref;
    }
};
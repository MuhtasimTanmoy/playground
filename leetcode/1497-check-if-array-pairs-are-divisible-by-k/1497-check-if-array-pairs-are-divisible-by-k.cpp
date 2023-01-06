class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        for (auto a: arr) {
            auto rem = ( a % k + k ) % k;
            counter[rem]++;
        }
        for (auto [rem, value]: counter) {
            if (!rem && (value & 1)) return false;
            if (rem && counter[rem] != counter[k-rem]) return false;
        }
        return true;
    }
};
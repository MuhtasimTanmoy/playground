class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto no_of_one = [](auto n) {
            return __builtin_popcount(n);
        };
        
        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            auto a_one = no_of_one(a), b_one = no_of_one(b);
            return a_one == b_one ? a < b: a_one < b_one;
        });
        
        return arr;
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> cache;
        auto comparator = [&](const int& a, const int& b) {
            auto ca = cache[a], cb = cache[b];
            return ca < cb;
        };
        auto convert = [&](const int& a) {
            auto aStr = to_string(a);
            for (int i = 0; i< aStr.size(); i++) aStr[i] = mapping[aStr[i] - '0'] + '0';
            return stoi(aStr);
        };
        for (auto num: nums) cache[num] = convert(num);
        sort(nums.begin(), nums.end(), comparator);
        return nums;
    }
};
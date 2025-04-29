class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (auto num: nums) counter[num]++;

        vector<vector<int>> freqMapper(nums.size() + 1);
        for (auto [key, freq]: counter) freqMapper[freq].push_back(key);

        reverse(begin(freqMapper), end(freqMapper));
        
        vector<int> res;
        for (auto elem: freqMapper)
            for (auto i: elem) {
                res.push_back(i);
                if (res.size() == k) return res;
            }
        return res;
    }
};
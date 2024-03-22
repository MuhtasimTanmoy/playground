class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0); int max_count = 0;
        for (auto num: nums) 
            max_count = max(max_count, ++freq[num]);
        int occur = 0;
        for (auto f: freq) if (f == max_count) occur++;
        return occur * max_count;
    }
};
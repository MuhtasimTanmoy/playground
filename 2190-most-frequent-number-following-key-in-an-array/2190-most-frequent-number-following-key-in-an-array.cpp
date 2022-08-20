class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> counter;
        int result = 0, keyMax = 0;
        for (int i = 0; i < nums.size() - 1; i++) 
            if (nums[i] == key) counter[nums[i + 1]]++;
        for (auto [key, value]: counter) 
            if (value > keyMax) {
                keyMax = value;
                result = key;
            }
        return result;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int res = 0) {
        unordered_map<int, int> counter;
        for (auto num: nums) counter[num]++;
        
        for (auto [_, count]: counter) {
            if (count == 1) return -1;
            while (count % 3) res++, count -= 2;
            res += count / 3;
        }
        return res;
    }
};
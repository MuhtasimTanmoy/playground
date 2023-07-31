class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> counter;
        for (auto num: nums) counter[num]++;
        
        int count = 0, max_num = 0;
        for (auto [key, val]: counter)
            if (val > count)
                max_num = key, count = val;
                
        for (int i = 0, curr = 0; i < len; i++) {
            if (nums[i] == max_num) curr++;
            auto l = curr * 2 > (i + 1),
                 r = (count - curr) * 2 > (len - i - 1);
            if (l && r) return i;
        }
        return -1;
    }
};
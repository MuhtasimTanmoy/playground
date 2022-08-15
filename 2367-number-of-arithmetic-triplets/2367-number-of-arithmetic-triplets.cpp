class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<int> list(201, 0);
        int result = 0;
        for (auto num: nums) list[num]++;
        for (int i = 0; i < list.size() - 2 * diff; i++) 
            if (list[i] && list[i + diff] && list[i + 2 * diff]) result++;
        return result;
    }
};
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> li(101, 0);
        for (auto num: nums) li[num]++;
        int res = 0;
        for (int i = 0; i < li.size(); i++) if (li[i] == 1) res += i;
        return res;
    }
};
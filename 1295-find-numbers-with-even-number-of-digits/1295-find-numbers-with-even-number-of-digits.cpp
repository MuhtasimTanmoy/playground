class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c = 0;
        for (auto &i: nums) {
            string s = to_string(i);
            if ((s.size() & 1) == 0) c++;
        }
        return c;
    }
};
/*
1303 / 1303 test cases passed, but took too long.

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            set<int> s {nums[i]};
            for (int j = i + 1; j < nums.size(); j++) {
                s.insert(nums[j]);
                int prev = -1, imbalance = 0;
                for (auto num: s) {
                    if (prev != -1) imbalance += (num - prev) > 1;
                    prev = num;
                }
                res += imbalance;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            int curr = 0;
            for (int j = i; j < nums.size(); j++) {
                auto num = nums[j];
                if (s.count(num)) {}
                else if (s.count(num - 1) && s.count(num + 1)) curr--;
                else if (!s.count(num - 1) && !s.count(num + 1) && s.size()) curr++;
                s.insert(num);
                res += curr;
            }
        }
        return res;
    }
};
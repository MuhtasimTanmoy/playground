class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> bag;
        for (auto task: tasks) bag[task]++;
        int round = 0;
        for (auto [key, val]: bag) {
            if (val == 1) return -1;
            if (val % 3 == 0)  round += val / 3;
            else round += val / 3 + 1;
        }
        return round;
    }
};
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for (int i : answers) c[i]++;
        int res = 0;
        for (auto [key, val] : c) res += (key+ val) / (key + 1) * (key + 1);
        return res;
    }
};
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, total = 0, n = grades.size();
        while (total + k < n) total += ++k;
        return k;
    }
};
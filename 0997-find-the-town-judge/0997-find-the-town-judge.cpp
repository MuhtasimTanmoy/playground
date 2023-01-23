class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> childCount(n + 1, 0);
        unordered_set<int> cantBe;
        for (auto t: trust) childCount[t[1]]++, cantBe.insert(t[0]);
        for (int i = 1; i < childCount.size(); i++) 
            if (childCount[i] == n - 1 && !cantBe.count(i)) return i;
        return -1;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> parent(n, 0);
        unordered_set<int> cantBe;
        for (auto t: trust) {
            parent[t[1] - 1]++;
            cantBe.insert(t[0]);
        }
        for (int i = 0; i < parent.size(); i++) 
            if (parent[i] == n - 1 && cantBe.count(i + 1) == 0) return i + 1;
        return -1;
    }
};
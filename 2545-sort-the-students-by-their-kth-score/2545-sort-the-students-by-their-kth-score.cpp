class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](auto prev, auto now) {
            return prev[k] > now[k];
        });
        return score;
    }
};
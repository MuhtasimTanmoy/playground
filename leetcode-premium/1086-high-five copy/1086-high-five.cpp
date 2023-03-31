class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> id_to_scores;
        for (auto item: items) {
            auto id = item[0], score = item[1];
            id_to_scores[id].push_back(score);
        }
        
        vector<vector<int>> res;
        for (auto [id, scores]: id_to_scores) {
            sort(scores.begin(), scores.end(), greater<int>());
            auto sum = accumulate(scores.begin(), scores.begin() + 5, 0);
            res.push_back({id, sum / 5});
        }
        return res;
    }
};
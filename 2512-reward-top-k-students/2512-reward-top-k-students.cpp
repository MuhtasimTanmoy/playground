class Solution {
public:
    vector<int> topStudents(vector<string>& pos_feed, 
                            vector<string>& neg_feed, 
                            vector<string>& report, 
                            vector<int>& student_id, int k) {
    unordered_set<string> pos(begin(pos_feed), end(pos_feed)), neg(begin(neg_feed), end(neg_feed));
    vector<pair<int, int>> sid;
    vector<int> res;
    for (int i = 0; i < report.size(); ++i) {
        int score = 0;
        for (int j = 0, k = 0; j <= report[i].size(); ++j)
            if (j == report[i].size() || report[i][j] == ' ') {
                score += pos.count(report[i].substr(k, j - k)) ? 3 : 
                    neg.count(report[i].substr(k, j - k)) ? -1 : 0;
                k = j + 1;
            }
        sid.push_back({-score, student_id[i]});
    }
    partial_sort(begin(sid), begin(sid) + k, end(sid));
    transform(begin(sid), begin(sid) + k, back_inserter(res), [](const auto &p){ return p.second; });
    return res;
}
};
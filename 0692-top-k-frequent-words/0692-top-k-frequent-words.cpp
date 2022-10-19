// Top K Frequency - > heap

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (auto word: words) counter[word]++;
        
        auto comp = [](const pair<int, string> a, const pair<int, string> b) {
            return (a.first < b.first) || (a.first == b.first && a.second > b.second);
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        for (auto [key, val]: counter) pq.push(make_pair(val, key));
        
        vector<string> res;
        while(k--) {
            auto top = pq.top(); pq.pop();
            res.push_back(top.second);
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, int> cnt;
//         for (string& word : words) cnt[word]++;

//         vector<pair<int, string>> candidates;
//         for (auto& p : cnt) candidates.push_back({-p.second, p.first});
//         sort(candidates.begin(), candidates.end());
        
//         vector<string> res;
//         for (int i = 0; i < k; i++) res.push_back(candidates[i].second);
//         return res;
//     }
// };
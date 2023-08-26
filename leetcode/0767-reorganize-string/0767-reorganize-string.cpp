class Solution {
public:
    string reorganizeString(string str) {
        vector<int> counter(26, 0);
        for (auto c: str) counter[c - 'a']++;
       
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) if (counter[i]) pq.push({counter[i], 'a' + i});
        
        string res = "";
        while (pq.size()) {
            auto [top_count, top_char] = pq.top(); pq.pop();
            if (res.size() && res.back() == top_char) {
                if (pq.size() == 0) return "";
                auto [second_count, second_char] = pq.top(); pq.pop();
                res += second_char; second_count--;
                if (second_count) pq.push({second_count, second_char});
                pq.push({top_count, top_char});
            } else {
                res += top_char;
                top_count--;
                if (top_count) pq.push({top_count, top_char});
            }
        }
        return res;
    }
};
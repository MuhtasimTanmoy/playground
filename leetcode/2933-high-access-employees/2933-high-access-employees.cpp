class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> mapper; 
        for (auto name_to_time: access_times)
            mapper[name_to_time.front()].push_back(name_to_time.back());
        
        auto to_time = [](string& s) -> int {
            int res = 0;
            for (int i = s.size() - 1, cnt = 1; i >= 0; i--)
                res += cnt * (s[i] - '0'),
                cnt *= 10;
            return res;
        };
        
        vector<string> res;
        for (auto [name, times]: mapper) {
            sort(times.begin(), times.end());
            for (auto i = 1; i < times.size() - 1; i++) {
                auto distance = to_time(times[i + 1]) - to_time(times[i - 1]);
                if (distance < 100) {
                    res.push_back(name);
                    break;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> map;
        
        for (auto &str: strs) {
            auto tmp = str;
            sort(tmp.begin(), tmp.end());
            if (map.find(tmp) == map.end()) {
                map[tmp] = res.size();
                res.push_back({str});
            } else {
                res[map[tmp]].push_back(str);
            }
        }
        return res;
    }
};
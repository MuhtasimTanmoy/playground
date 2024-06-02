class Solution {
public:
    vector<string> wordBreak(string s, 
                             vector<string>& dict) {
        unordered_set<string> bag(dict.begin(), dict.end());
        vector<string> res;
        
        unordered_set<string> cache; 
        auto gen_key = [](int i, string a) {
             return to_string(i) + "-" + a; 
        };
        
        function<void(int, string)> go = [&](auto idx, string prev) {
            if (idx == s.size()) 
                prev.pop_back(), res.push_back(prev);
            else {
                auto key = gen_key(idx, prev);
                if (cache.count(key)) return;

                string builder = "";
                for (int i = idx; i < s.size(); i++) {
                    builder += s[i];
                    if (bag.count(builder)) go(i + 1, prev + builder + " ");
                }
            }
        };
        go(0, "");
        return res;
    }
};
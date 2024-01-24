class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(), dict.end(), [&](auto l, auto r) {
            if (l.size() == r.size()) return l > r;
            else return l.size() < r.size();
        });
        auto go = [&](string& now) {
            int i = 0;
            for (auto c: s) if (i < now.size() && now[i] == c) i++;
            return i == now.size();
        };
        for (int i = dict.size() - 1; i >= 0; i--)
            if (go(dict[i]))
                return dict[i];
        return "";    
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& fs, string pre = "", vector<string> res = {}) {
        sort(fs.begin(), fs.end());
        for (auto &f: fs) f.push_back('/');
        for (auto c: fs) 
            if (pre.empty() || !c.starts_with(pre))
                pre = c,
                res.push_back(c);
        for (auto &s: res) s.pop_back();
        return res;
    }
};
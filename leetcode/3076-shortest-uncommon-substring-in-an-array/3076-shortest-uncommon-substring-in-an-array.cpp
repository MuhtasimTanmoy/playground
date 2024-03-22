class Solution {
public:
    set<pair<int, string>> sub(string s) {
        set<pair<int, string>> S;
        for (int i = 0; i < s.size(); ++i) {
            string ss;
            for (int j = i; j < s.size(); ++j)
                ss += s[j],
                S.insert(make_pair((int) ss.size(), ss));
        }
        return S;
    }
    
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<pair<int, string>, int> M;
        for (auto s : arr) {
            auto S = sub(s);
            for (auto& p : S) M[p]++;
        }
        
        vector<string> res;
        for (auto s :arr) {
            auto S = sub(s);
            for (auto& p : S) {
                if (M[p] == 1) {
                    res.push_back(p.second);
                    goto next;
                }
            }
            res.push_back("");
            next:;
        }
        
        return res;
    }
};
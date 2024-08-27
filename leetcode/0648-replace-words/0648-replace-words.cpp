class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_set<string> bag(d.begin(), d.end());
        
        string res = "", token;
        stringstream ss(s); 
        while (ss >> token) {
            string now = ""; bool can_add = true;
            for (auto c: token) {
                now += c;
                if (bag.count(now)) {
                    res += now, res += " ";
                    can_add = false;
                    break;
                }
            }
            if (can_add) res += token, res += " ";
        }
        res.pop_back();
        return res;
    }
};
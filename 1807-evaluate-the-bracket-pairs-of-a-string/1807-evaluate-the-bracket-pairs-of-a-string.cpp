class Solution {
public:
    string evaluate(const string s, const vector<vector<string>>& knowledge) {
        unordered_map<string,string> um;
        for(const auto& i:knowledge) um[i[0]] = i[1];
        string res, key;
        bool bracket = false;
        for (auto i :s) {
            if ( !isalpha(i) )
                if ( i == ')' ) {
                    um.count(key) ? res += um[key] : res += '?';
                    bracket = false;
                    key.clear();
                } else bracket = true;
            else bracket ? key += i: res += i;
        }
        return res;
    }
};
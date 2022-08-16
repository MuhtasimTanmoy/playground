class Solution {
public:
    string greatestLetter(string s) {
        auto distance = abs('a' - 'A');
        string ans = "";
        vector<int> res(127, 0);
        for (auto c: s) res[c]++;
        for (int i = 126; i >= 0; i--) 
            if (res[i] && res[i-distance]) {
                ans.push_back(char(i-distance));
                return ans;
            }
        return ans;
    }
};
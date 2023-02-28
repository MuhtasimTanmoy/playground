class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> preSum(words.size() + 1);
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        auto isStartEndVowel = [isVowel](string& w) {
            return isVowel(w[0]) && isVowel(w.back());
        };
        for (auto i = 1; i <= words.size(); i++)
            preSum[i] = isStartEndVowel(words[i - 1]) + preSum[i - 1];
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto query = queries[i];
            res[i] = preSum[query[1] + 1] - preSum[query[0]];
        }
        return res;
    }
};
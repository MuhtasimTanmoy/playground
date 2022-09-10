class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mapping(128, 0);
        int maxOccur = 0;
        for (int j = 0, i = 0; j < s.size(); j++) {
            maxOccur = max(maxOccur, ++mapping[s[j]]);
            if (j - i + 1 > maxOccur + k) mapping[s[i++]]--;
        }
        return min((int)s.size(), maxOccur + k);
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strCount = strs.size(), minStrSize = INT_MAX;
        for (auto str: strs) minStrSize = min(minStrSize, (int) str.size());
        for (int i = 1; i < strs.size(); i++) 
            for (int j = 0; j < minStrSize; j++)
                if (strs[0][j] != strs[i][j]) {
                    minStrSize = j;
                    break;
                }
        return strs[0].substr(0, minStrSize);
    }
};
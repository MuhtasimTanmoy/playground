class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del = 0;
        for (int index = 0; index < strs[0].size(); index++) {
            auto elem = strs[0][index];
            for (auto str:  strs) {
                if (str[index] < elem) {
                    del++;
                    break;
                }
                elem = str[index];
            }
        }
        return del;
    }
};
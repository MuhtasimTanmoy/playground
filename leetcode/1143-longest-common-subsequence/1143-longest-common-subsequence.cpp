class Solution {
public:
    int longestCommonSubsequence(string text1, 
                                 string text2) {
        vector<vector<int>> li(2, vector<int>(text2.size() + 1));
        for (int i = 0; i < text1.size(); i++)
            for (int j = 0; j < text2.size(); j++)
                li[(i + 1) % 2][j + 1] = 
                text1[i] == text2[j] 
                ? li[i%2][j] + 1: max(li[(i)%2][j+1], li[(i+1)%2][j]);
        return li[text1.size()%2][text2.size()];
    }
};
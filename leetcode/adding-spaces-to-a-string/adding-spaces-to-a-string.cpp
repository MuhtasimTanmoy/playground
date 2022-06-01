class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int total = size(s) + size(spaces);
        string result(total, ' ');
        int itr = 0;
        int itrSpace = 0;
        for(int i = 0; i < size(s); i++) {
            if (itrSpace < size(spaces) && spaces[itrSpace] == i) {
                itr++;
                itrSpace++;
            }
            result[itr++] = s[i];
        }
        return result;
    }
};
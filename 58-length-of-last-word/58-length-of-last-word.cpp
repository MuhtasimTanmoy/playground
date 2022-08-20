class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int len = 0;
        while(ss >> word) len = word.size();
        return len;
    }
};
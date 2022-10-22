class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> tracker(26, 0);
        for (auto c: sentence) tracker[c-'a']++;
        for (auto count: tracker) if (!count) return false;
        return true;
    }
};
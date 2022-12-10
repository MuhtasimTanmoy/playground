class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string now, prev = "", firstCache;
        while (ss >> now) {
            if (prev.size()) { if (prev.back() != now.front()) return false; }
            else firstCache = now;
            prev = now;
        }
        return firstCache.front() == now.back();
    }
};
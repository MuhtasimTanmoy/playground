class Solution {
public:
    char kthCharacter(int k) {
        string now = "a";
        while ( (int) now.size() < k) {
            auto temp = now;
            for (auto c: now) temp += 'a' + (c - 'a' + 1) % 26;
            now = temp;
        }
        return now[k - 1];
    }
};
class Solution {
public:
    string freqAlphabets(string s) {
        deque<char> list;
        for (int i = s.size() - 1; i >= 0; i--) {
            int index = 0;
            if (s[i] == '#') {
                index = s[--i] - '0';
                index = index + ((s[--i] - '0') * 10);
            } else index = s[i] - '0';
            list.push_front('a' + index - 1);
        }
        return string(list.begin(), list.end());
    }
};
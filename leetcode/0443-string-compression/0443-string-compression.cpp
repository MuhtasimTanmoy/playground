class Solution {
public:
    int compress(vector<char>& chars) {
        int counter = 1;
        int l = 0, itr = 0;
        for (auto c: chars) {
            if (itr && chars[itr] == chars[itr - 1]) counter++;
            else {
                if (counter >= 2) {
                    auto cntStr = to_string(counter);
                    for (auto c: cntStr) chars[l++] = c;
                }
                chars[l++] = c;
                counter = 1;
            }
            itr++;
        }
        if (counter >= 2) {
            auto cntStr = to_string(counter);
            for (auto c: cntStr) chars[l++] = c;
        }
        return l;
    }
};
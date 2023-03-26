class Solution {
public:
    string countAndSay(int n) {
        string last = "1";
        auto count = [&]() {
            string builder = "";
            for (int i = 0, left = 0; i < last.size();) {
                while (last[i] == last[left]) i++;
                builder += to_string(i - left);
                builder += last[left];
                left = i;
            }
            return builder;
        };
        for (int i = 1; i < n; i++) last = count();
        return last;
    }
};
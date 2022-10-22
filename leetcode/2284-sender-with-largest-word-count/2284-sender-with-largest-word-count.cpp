class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> wordCounter;
        for (int i = 0; i < messages.size(); i++) {
            auto sender = senders[i]; int count = 1;
            for (auto c: messages[i]) if (c == ' ') count++;
            wordCounter[sender] += count;
        }
        vector<string> large;
        int largest = -1;
        for (auto [key, val]: wordCounter) {
            if (val < largest) continue;
            if (val > largest) {
                large.clear();
                largest = val;
            }
            large.push_back(key);
        }
        sort(large.begin(), large.end());
        return large.back();
    }
};
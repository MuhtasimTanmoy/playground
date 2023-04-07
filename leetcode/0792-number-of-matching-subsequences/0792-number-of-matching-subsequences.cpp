// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& w) {
//         unordered_set<string> bag(w.begin(), w.end());
//         function<int(int, string)> go = [&](auto i, string take) -> int {
//             if (i == s.size()) return bag.count(take);
//             int with = go(i + 1, take + s[i]),
//                  without = go(i + 1, take);
//             return with + without;
//         };
//         return go(0, "");
//     }
// };

struct Node {
    const string& word;
    int index;
    Node(const string &word, int index) : word(word), index(index) {}
};

class Solution {
public:
    int numMatchingSubseq(const string& s, vector<string>& words) {
        vector<Node> buckets[26];
        for (string& word : words) {
            char startingChar = word[0];
            buckets[startingChar-'a'].emplace_back(word, 0);
        }
        int ans = 0;
        for (char c : s) {
            auto currBucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            for (Node& node : currBucket) {
                ++node.index;
                if (node.index == node.word.size()) 
                    ++ans;
                else 
                    buckets[node.word[node.index]-'a'].push_back(node);
            }
        }
        return ans;
    }
};
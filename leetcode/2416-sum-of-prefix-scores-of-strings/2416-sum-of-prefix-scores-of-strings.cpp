class TrieNode {
public:
    int cnt = 0;
    TrieNode* has[26] = {NULL};
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(string s) {
        auto itr = root;
        for (auto c: s) {
            auto idx = c - 'a';
            if (itr->has[idx] == NULL) itr->has[idx] = new TrieNode();
            itr->has[idx]->cnt++;
            itr = itr->has[idx];
        }
    }
    
    int get(string s) {
        auto itr = root;
        int cnt = 0;
        for (auto c: s) {
            auto idx = c - 'a';
            if (itr->has[idx] != NULL) cnt += itr->has[idx]->cnt; else break;
            itr = itr->has[idx];
        }
        return cnt;
    }
};

class Solution {
    Trie* t = new Trie();
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto word: words) t->insert(word);
        vector<int> res;
        for (auto word: words) res.push_back(t->get(word));
        return res;
    }
};
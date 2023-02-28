/*
class TrieNode {
public:
    TrieNode* bits[26];
    bool is_word[26];
    bool has(int index) { return bits[index]; }
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(const string& s) {
        auto itr = root;
        for (auto i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (itr->bits[idx] == NULL) itr->bits[idx] = new TrieNode();
            if (i == s.size() - 1) itr->is_word[idx] = true;
            itr = itr->bits[idx];
        }
    }
    
    void find(TrieNode* node, int& left, vector<string>& res, string& builder) {
        if (left <= 0 || node == NULL) return;
        for (int i = 0; i < 26; i++)
            if (node->has(i) && left) {
                builder.push_back('a' + i);
                if (node->is_word[i]) --left, res.push_back(builder);
                find(node->bits[i], left, res, builder);
                builder.pop_back();
            }
    }
        
    vector<string> top_three(const string& search_token) {
        vector<string> res;
        auto itr = root;
        for (auto i = 0; i < search_token.size(); i++) {
            int idx = search_token[i] - 'a';
            if (itr && itr->has(idx)) {
                if (i == search_token.size() - 1 
                    && itr->is_word[idx]) res.push_back("");
                itr = itr->bits[idx]; 
            } else return {};
        }
        int find_count = 3;
        string builder = "";
        find(itr, find_count, res, builder);
        for (int i = 0; i < res.size(); i++) res[i] = search_token + res[i];
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, 
                                             string searchWord) {
        vector<vector<string>> res;
        auto trie = new Trie();
        for (auto product: products) trie->insert(product);
        string builder = "";
        for (auto search_token: searchWord) {
            builder += search_token;
            auto top_match_lex = trie->top_three(builder);
            res.push_back(top_match_lex);
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};
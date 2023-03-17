class Trie {
public:
    Trie* nodes[26] = {};
    bool is_word = false;
    bool contains(int idx) { return nodes[idx] != NULL; }
    void set(int idx) { nodes[idx] = new Trie(); }
    Trie* next(int idx) { return nodes[idx]; }
};

class WordDictionary {
public:
    WordDictionary() {
        head = new Trie();
    }
    
    void addWord(string word) {
        auto itr = head;
        for (auto c: word) {
            auto idx = c - 'a';
            if (itr->contains(idx) == false) itr->set(idx);
            itr = itr->next(idx);
        }
        itr->is_word = true;
    }
    
    bool search(string word, Trie* start = NULL) {
        auto curr = start ? start: head;
        for (auto i = 0; i < word.size(); i++) {
            auto c = word[i];
            if (c != '.') {
                auto idx = c - 'a';
                if (curr->contains(idx) == false) return false;
                curr = curr->next(idx);
            } else {
                for (auto node: curr->nodes) 
                    if (node)
                        if (search(word.substr(i+1), node))
                            return true;
                return false;
            }
        }
        return curr->is_word;
    }
private:
    Trie* head;
};
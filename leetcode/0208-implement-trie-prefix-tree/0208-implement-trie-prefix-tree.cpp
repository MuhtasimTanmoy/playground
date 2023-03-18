class Trie {
public:
    Trie() {}
    
    void insert(string word) {
        auto curr = this;
        for (auto c: word) {
            auto idx = c - 'a';
            if (!curr->contains(idx)) curr->set(idx);
            curr = curr->next(idx);
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        auto curr = this;
        for (auto c: word) {
            auto idx = c - 'a';
            if (!curr->contains(idx)) return false;
            curr = curr->next(idx);
        }
        return curr->isWord == true;
    }
    
    bool startsWith(string prefix) {
        auto curr = this;
        for (auto c: prefix) {
            auto idx = c - 'a';
            if (!curr->contains(idx)) return false;
            curr = curr->next(idx);
        }
        return true;
    }
private:
    Trie* nodes[26] = {};
    bool isWord = false;
    
    bool contains(int idx) {
        return nodes[idx] != NULL;
    }
    
    void set(int idx) {
        nodes[idx] = new Trie();
    }
    
    Trie* next(int idx) {
        return nodes[idx];
    }
};
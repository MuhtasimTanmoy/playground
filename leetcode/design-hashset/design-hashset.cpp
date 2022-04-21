class MyHashSet {
    unordered_set<int> hash;
public:
    MyHashSet() {}
    
    void add(int key) {
        hash.insert(key);
    }
    
    void remove(int key) {
        hash.erase(key);
    }
    
    bool contains(int key) {
        return hash.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
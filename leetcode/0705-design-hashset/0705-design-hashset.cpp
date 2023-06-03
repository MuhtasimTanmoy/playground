class MyHashSet {
    int map[1000001];
public:
    MyHashSet() {}
    void add(int key) { map[key] = 1; }
    void remove(int key) { map[key] = 0; }
    bool contains(int key) { return map[key] == 1; }
};
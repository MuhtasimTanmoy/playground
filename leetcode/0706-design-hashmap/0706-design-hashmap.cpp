class MyHashMap {
    vector<int> v;
public:
    MyHashMap() { v = vector<int>(1000001,-1); }
    void put(int key, int value) { v[key] = value; }
    int get(int key) { return v[key]; }
    void remove(int key) { v[key] = -1; }
};
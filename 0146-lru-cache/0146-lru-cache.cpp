class LRUCache {
list<pair<int, int>> dll;
unordered_map<int, list<pair<int, int>>::iterator> m;
int capacity;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }

    int get(int key) {
        if(m.count(key) == 0) return -1;
        auto itr = m[key];
        auto item = *itr;
        dll.erase(itr);
        dll.push_front(item);
        m[key] = dll.begin();
        return item.second;
    }

    void put(int key, int value) {
        if(m.count(key) == 1) {
            // If key exists, update value for that key
            auto itr = m[key];
            dll.erase(itr);
            dll.push_front({key, value});
            m[key] = dll.begin();
        } else {
            if(dll.size() >= capacity) {
                // Evict LRU
                auto item = dll.back();
                dll.pop_back();
                m.erase(item.first);
            }
            // Insert new key, val
            dll.push_front({key, value});
            m[key] = dll.begin();
        }
    }
};
class TimeMap {
    unordered_map<string, map<int, string>> storage;
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        storage[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = storage[key].upper_bound(timestamp);
        return it == storage[key].begin() ? "" : prev(it)->second;
    }
};
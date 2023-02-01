class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyValFreq;
    unordered_map<int, list<int>> freqKey;
    unordered_map<int, list<int>::iterator> keyIter;

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end()) return -1;
        
        int freq = keyValFreq[key].second;
        freqKey[freq++].erase(keyIter[key]);
        freqKey[freq].emplace_front(key);
        
        keyIter[key] = freqKey[freq].begin();
        keyValFreq[key].second = freq;
        if (freqKey[minFreq].empty()) minFreq = freq;
        
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        
        if (get(key) != -1) {
            keyValFreq[key].first = value;
            return;
        }

        if (keyValFreq.size() == capacity) {
            int delKey = freqKey[minFreq].back();
            freqKey[minFreq].pop_back();
            keyValFreq.erase(delKey);
            keyIter.erase(delKey);
        }

        minFreq = 1;
        keyValFreq[key] = make_pair(value, minFreq);
        freqKey[minFreq].emplace_front(key);
        keyIter[key] = freqKey[minFreq].begin();
    }
};
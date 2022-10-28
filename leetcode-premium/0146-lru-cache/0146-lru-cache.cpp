class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if (!storage.count(key)) return -1;
        
        auto itr = storage[key];
        auto item = *itr;
        dll.erase(itr);
        
        dll.push_front(item);
        storage[key] = dll.begin();
        return item.second;
    }
    
    void put(int key, int value) {
        
        if (storage.count(key)) {
            auto itr = storage[key];
            dll.erase(itr);
            dll.emplace_front(key, value);
            storage[key] = dll.begin();
            return;
        }
        
        if (dll.size() == capacity) {
            auto item = dll.back();
            dll.pop_back();
            storage.erase(item.first);
        }
        
        dll.emplace_front(key, value);
        storage[key] = dll.begin();
    }
private:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> storage;
    int capacity;
};


// class LRUCache {
    
//     int cap;
//     list< pair<int, int> > holder;
//     unordered_map<int, list< pair<int, int> >::iterator> indexMapper;
        
// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//     }
    
//     int get(int key) {
//         if (!indexMapper.count(key)) return -1;
        
//         auto itr = *indexMapper[key];
//         holder.erase(indexMapper[key]);
//         holder.insert(holder.begin(), itr);
        
//         indexMapper[key] = holder.begin();
//         return itr.second;
//     }
    
//     void put(int key, int value) {
//         if (get(key) != -1) 
//             indexMapper[key]->second = value;
//         else {
//             pair<int, int> item = {key, value};
//             holder.insert(holder.begin(), item);
//             indexMapper[key] = holder.begin();
            
//             if (holder.size() > cap) {
//                 indexMapper.erase(holder.back().first);
//                 holder.pop_back();
//             }
//         }
//     }
// };
class RandomizedSet {
    unordered_map<int, int> bag;
    vector<int> data;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (bag.count(val) == 0) {
            bag[val] = data.size();
            data.push_back(val);
            return true;
        } else return false;
    }
    
    bool remove(int val) {
        if (bag.count(val) == 0) return false;
        
        auto currIndexToRemove = bag[val];
        data[currIndexToRemove] = data.back();
        bag[data.back()] = currIndexToRemove;
        
        data.pop_back();
        bag.erase(val);
        return true;
    }
    
    int getRandom() {
        auto index = rand() % data.size();
        return data[index];
    }
};
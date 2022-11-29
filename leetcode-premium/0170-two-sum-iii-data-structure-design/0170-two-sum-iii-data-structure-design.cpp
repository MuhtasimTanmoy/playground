class TwoSum {
private:
    std::unordered_map<long long, int> umap;
public:
    TwoSum() {}
    void add(int n) { ++umap[n]; }
    
    bool find(int val) {
        for (auto [num, count]: umap) {
            long long comp = val - num;
            if (comp == num ? count > 1 : umap.count(comp) != 0)
                return true;
        }
        return false;
    }
};
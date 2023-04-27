class SmallestInfiniteSet {
    int counter = 1;
    set<int> s;
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if (s.empty()) return counter++;
        
        auto small = *s.begin();
        if (small <= counter) { 
            s.erase(small);
            if (small == counter) counter++;
            return small;
        }
        
        return counter++;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
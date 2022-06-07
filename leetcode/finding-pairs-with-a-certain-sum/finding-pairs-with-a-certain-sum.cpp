class FindSumPairs {
    vector<int> stable;
    vector<int> changed;
    
    unordered_map<int, int> bag;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        stable = nums1;
        changed = nums2;
        for(auto elem: changed) bag[elem]++;
    }
    
    void add(int index, int val) {
        bag[changed[index]]--;
        changed[index] += val;
        bag[changed[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for(auto elem: stable) count += bag.count(tot-elem) ? bag[tot-elem] : 0 ;
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
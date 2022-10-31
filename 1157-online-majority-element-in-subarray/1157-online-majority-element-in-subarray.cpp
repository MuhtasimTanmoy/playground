// Naive Approach
/*
class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        list = arr;
    }
    
    int query(int left, int right, int threshold) {
        int count = 0, val = -1;
        unordered_map<int, int> counter;
        for (int i = left; i <= right; i++) {
            auto num = list[i];
            counter[num]++;
        }
        
        for (auto [key, keycount]: counter) 
            if (keycount >= threshold && keycount > count ) {
                count = keycount;
                val = key;
            }
        return val;
    }
private:
    vector<int> list;
};
*/

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
      for (auto i = 0; i < arr.size(); ++i) idx[arr[i]].push_back(i);
      a = arr;
    }
    
    int query(int left, int right, int threshold) {
      for (auto n = 0; n < 10; ++n) {
        auto i = idx.find(a[left + rand() % (right - left + 1)]);
        if (i->second.size() < threshold) continue;
        if (upper_bound(begin(i->second), end(i->second), right) - 
            lower_bound(begin(i->second), end(i->second), left) >= threshold) 
            return i->first;
      }
      return -1;
    }
private:
    vector<int> a;
    unordered_map<int, vector<int>> idx;
};
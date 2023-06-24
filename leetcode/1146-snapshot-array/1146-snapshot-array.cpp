/*
class SnapshotArray {
    vector<vector<int>> keep;
public:
    SnapshotArray(int length) {
        auto v = vector<int>(length, 0);
        keep.push_back(v);
    }
    
    void set(int index, int val) {
        keep.back()[index] = val;
    }
    
    int snap() {
        auto copy = keep.back();
        keep.push_back(copy);
        return keep.size() - 2;
    }
    
    int get(int index, int snap_id) {
        return keep[snap_id][index];
    }
};
*/

class SnapshotArray {
    unordered_map<int, map<int, int>> a;
    int cur_snap = 0;
public:
    SnapshotArray(int length) {}
    
    int snap() { return cur_snap++; }
    void set(int index, int val) { a[index][cur_snap] = val; }
    
    int get(int index, int snap_id) {
      auto it = a[index].upper_bound(snap_id);
      return it == begin(a[index]) ? 0 : prev(it)->second;
    }
};


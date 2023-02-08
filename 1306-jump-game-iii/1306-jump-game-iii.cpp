class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
        function<bool(int)> go = [&](auto idx) {
            if (idx < 0 || idx >= arr.size()) return false;
            if (!arr[idx]) return true;
                        
            if (visited.count(idx)) return false;
            visited.insert(idx);
            
            return go(idx + arr[idx]) || go(idx - arr[idx]);
        };
        return go(start);
    }
};
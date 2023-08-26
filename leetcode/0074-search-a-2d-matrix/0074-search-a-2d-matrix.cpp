class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        
        auto search = [&](vector<int>& a) {
            int left = 0, right = a.size() - 1;
            while (left <= right) {
                auto mid = left + (right - left) / 2;
                if (a[mid] == target)
                    return true;
                else if (a[mid] > target)
                    right = mid - 1;
                else left = mid + 1;
            }
            return false;
        };
        
        
        int lo = 0, hi = m.size() - 1;
        while (lo <= hi) {
            auto mid = lo + (hi - lo) / 2;
            
            auto first_in_row = m[mid][0];
            if (target < first_in_row) {
                hi = mid - 1;
                continue;
            }
            
            auto last_in_row = m[mid].back();
            if (target > last_in_row) {
                lo = mid + 1;
                continue;
            }
            cout<<"here"<<endl;
            return search(m[mid]);
        }
        
        return false;
    }
};
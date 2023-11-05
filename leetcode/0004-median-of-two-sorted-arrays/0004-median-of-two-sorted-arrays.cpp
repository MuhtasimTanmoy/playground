class Solution {
public:
    double findMedianSortedArrays(vector<int>& l, vector<int>& r) {
        int li = 0, ri = 0;
        auto extractNext = [&]() -> int {
            if (li == l.size()) return r[ri++];
            if (ri == r.size()) return l[li++];
            return l[li] < r[ri] ? l[li++]: r[ri++];
        };
                
        int total = l.size() + r.size(), targetIndex = (total - 1) / 2, currentItem = 0;
        bool isOdd = (total & 1);
        
        for (int i = 0; i < total; i++) {
            currentItem = extractNext();
			if ( i < targetIndex ) continue;
            
            if (isOdd) return currentItem;
            else return (currentItem + extractNext()) / 2.0;
        }
        return 0;
    }
};
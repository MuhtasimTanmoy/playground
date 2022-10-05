class Solution {
    struct Elem {
        int val;
        int index;
        int rank;
        Elem(int v, int i, int r): val(v), index(i), rank(r){}
    };
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<Elem> elems;
        
        int itr = 0;
        for(auto a: arr) elems.emplace_back(a, itr++, 0);
        sort(elems.begin(), elems.end(), [&](const Elem& a, const Elem& b) {
            return a.val < b.val;
        });
        
        int last = -1;
        int rank = 0;
        for(int i = 0; i < size(elems); i++) {
            if (elems[i].val == last) elems[i].rank = rank;
            else {
                elems[i].rank = ++rank;
                last = elems[i].val;
            }
        }
        sort(elems.begin(), elems.end(), [&](const Elem& a, const Elem& b) {
            return a.index < b.index;
        });
        
        vector<int> result;
        for(auto a: elems) result.push_back(a.rank);
        return result;
    }
};
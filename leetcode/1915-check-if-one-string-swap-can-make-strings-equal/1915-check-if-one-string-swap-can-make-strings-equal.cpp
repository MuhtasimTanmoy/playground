class Solution {
public:
    bool areAlmostEqual(string l, string r) {
        if (l == r) return true;
        
        vector<int> differs;
        for (auto i = 0; i < l.size(); i++)
            if (l[i] != r[i])
                differs.push_back(i);
        if (differs.size() != 2) return false;
        auto li = differs.front(), ri = differs.back();
        if (l[li] == r[ri] && r[li] == l[ri]) return true;
        return false;
    }
};
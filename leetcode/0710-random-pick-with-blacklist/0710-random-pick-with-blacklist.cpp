// class Solution {
//     unordered_set<int> bag;
//     int range;
// public:
//     Solution(int n, vector<int>& blacklist) {
//         bag = unordered_set<int>(blacklist.begin(), blacklist.end());
//         range = n;
//     }
    
//     int pick() {
//         int item;
//         do { item = rand() % range; } while (bag.count(item));
//         return item;
//     }
// };  


class Solution {
public:

    unordered_map<int, int> m;
    int wlen;

    Solution(int n, vector<int> b) {
        wlen = n - b.size();
        unordered_set<int> w;
        for (int i = wlen; i < n; i++) w.insert(i);
        for (int x : b) w.erase(x);
        auto wi = w.begin();
        for (int x : b)
            if (x < wlen)
                m[x] = *wi++;
    }

    int pick() {
        int k = rand() % wlen;
        return m.count(k) ? m[k] : k;
    }
};
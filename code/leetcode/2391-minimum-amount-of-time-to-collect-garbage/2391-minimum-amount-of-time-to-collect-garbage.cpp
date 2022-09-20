class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for (int i = 1; i< travel.size(); i++) travel[i] += travel[i-1];
        int cost = 0; unordered_set<char> bag;
        for (int i = garbage.size() - 1; i >= 0; i--) {
            auto multiples = garbage[i];
            cost += multiples.size();
            for (auto c: multiples) 
                if (!bag.count(c)) {
                    if (i) cost+= travel[i-1];
                    bag.insert(c);
                }
        }
        return cost;
    }
};

// int garbageCollection(vector<string>& garb, vector<int>& travel) {
//     int dist[128] = {};
//     partial_sum(begin(travel), end(travel), begin(travel));
//     for (int i = 1; i < garb.size(); ++i)
//         for (auto g : garb[i])
//             dist[g] = travel[i - 1];
//     return accumulate(begin(garb), end(garb), 0, [](int sz, const auto& g) { return sz + g.size(); })
//         + accumulate(begin(dist), end(dist), 0);
// }
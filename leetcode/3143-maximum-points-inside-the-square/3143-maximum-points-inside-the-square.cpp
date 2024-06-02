class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> strip;
        for (auto point: points) {
            auto now = max(abs(point.front()), abs(point.back()));
            strip.push_back(now);
        }
        unordered_map<char, int> track;
        int discard = INT_MAX;
        for (auto i = 0; i < strip.size(); i++) {
            auto now =  strip[i];
            if (track.count(s[i]) == 0) {
                track[s[i]] = now;
                continue;
            }
            
            if (now < track[s[i]]) swap(track[s[i]], now);
            discard = min(now, discard);
        }
                        
        int res = 0;
        for (auto i: strip) if (i < discard) res++;
        return res;
    }
};
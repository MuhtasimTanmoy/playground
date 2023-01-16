class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        auto myDistance = abs(target[0]) + abs(target[1]);
        // cout<<myDistance<<endl;
        for (auto ghost: ghosts) {
            auto distance = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            // cout<<distance<<endl;
            if (distance <= myDistance) return false;
        }
        return true;
    }
};
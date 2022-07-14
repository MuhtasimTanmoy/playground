class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (auto stone: asteroids)
            if (stone < 0) {
                while (stk.size() && stk.back() > 0 && stk.back() < abs(stone)) stk.pop_back();
                if (stk.empty() || stk.back() < 0) stk.push_back(stone);
                else if (stk.size() && stk.back() == abs(stone)) stk.pop_back();
            } else stk.push_back(stone);
        return stk;
    }
};
class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& asteroids) {
        long long mass = m;
        sort(asteroids.begin(), asteroids.end());
        for (auto asteroid: asteroids) {
            if (mass < asteroid) return false;
            mass += asteroid;
        }
        return true;
    }
};
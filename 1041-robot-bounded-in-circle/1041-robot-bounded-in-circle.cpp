class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> traverse = make_pair(0, 0);
        
        auto selectedIndex = 0;
        vector<pair<int, int>> direction = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        
        auto goLeft = [&]() {
            selectedIndex += 1;
            selectedIndex %= 4;
        };
        
        auto goRight = [&]() {
            selectedIndex -= 1;
            selectedIndex = (selectedIndex + 4) % 4;
        };
        
        for (int i = 0; i < 4; i++) {
            for (auto instruction: instructions) {
                auto move = direction[selectedIndex];
                
                // improve
                if (instruction == 'G') {
                    traverse.first += move.first;
                    traverse.second += move.second;
                } else if (instruction == 'L') {
                    goLeft();
                } else if (instruction == 'R') {
                    goRight();
                } else throw "INVALID_INPUT";
            }
            if (traverse.first == 0 && traverse.second == 0) return true;
        }
        return false;
    }
};
// class Solution {
// public:
//     bool isRobotBounded(string instructions) {
//         pair<int, int> traverse = make_pair(0, 0);
        
//         auto selectedIndex = 0;
//         vector<pair<int, int>> direction = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        
//         auto goLeft = [&]() {
//             selectedIndex += 1;
//             selectedIndex %= 4;
//         };
        
//         auto goRight = [&]() {
//             selectedIndex -= 1;
//             selectedIndex = (selectedIndex + 4) % 4;
//         };
        
//         for (int i = 0; i < 4; i++) {
//             for (auto instruction: instructions) {
//                 auto move = direction[selectedIndex];
                
//                 // improve, switch case
//                 if (instruction == 'G') {
//                     traverse.first += move.first;
//                     traverse.second += move.second;
//                 } else if (instruction == 'L') {
//                     goLeft();
//                 } else if (instruction == 'R') {
//                     goRight();
//                 } else throw "INVALID_INPUT";
//             }
//             if (traverse.first == 0 && traverse.second == 0) return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};
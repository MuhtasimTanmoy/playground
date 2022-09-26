// class Solution {
// public:
//     bool equationsPossible(vector<string>& equations) {
//         unordered_map<int, int> mapping;
//         int generator = 0;
        
//         for(auto equation: equations) {
//             auto left = equation[0];
//             auto right = equation[3];
//             auto isEqual = equation[1] == '=';
//             if (left == right && !isEqual) return false;
//             if (mapping.count(left) && mapping.count(right)) {
//                 if (isEqual && mapping[left] != mapping[right]) return false;
//                 else if (!isEqual && mapping[left] == mapping[right]) return false;
//             } else {
//                 if (mapping.count(right) == 0) mapping[right] = isEqual ? generator: ++generator;
//                 if (mapping.count(left) == 0) mapping[left] = isEqual ? generator: ++generator;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        constexpr int SIZE = 26;
        vector<vector<int>> graph(SIZE);
        vector<int> color(SIZE, -1);
        
        for (string& eqn : equations)
            if (eqn[1] == '=') {
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }

        // mark the color of `node` as `c`
        function<void(int, int)> dfs = [&](int node, int c) {
            if (color[node] == -1) {
                color[node] = c;
                for (int nei : graph[node]) dfs(nei, c);
            }
        };

        for (int i = 0; i < SIZE; i++) dfs(i, i);
        for (string& eqn : equations)
            if (eqn[1] == '!') {
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                if (color[x] == color[y]) return false;
            }
        return true;
    }
};


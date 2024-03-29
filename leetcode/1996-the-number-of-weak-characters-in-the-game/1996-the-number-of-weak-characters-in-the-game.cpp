// // Brute force dont work O(n^2)
// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
//         sort(properties.begin(), properties.end(),
//              [&](const vector<int> &a, const vector<int> &b) {
//             return a[0] < b[0] || ( a[0] == b[0] && a[1] > b[1] );
//         });
//         int maxDefence = 0;
//         auto isWeak = [&](vector<int>& a) -> bool {
//             maxDefence = max(maxDefence, a[1]);
//             return a[1] < maxDefence ? true : false;
//         };
//         int res = 0;
//         for(int i = size(properties) - 1; i >= 0; i--) if (isWeak(properties[i])) res++;
//         return res;
//     }
// };

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), 
             [](const vector<int>& a, vector<int>& b) -> bool { 
                 return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);});
        int weakCharacters = 0, maxDefense = 0;
        for (int i = (int)properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < maxDefense) weakCharacters++;
            maxDefense = max(maxDefense, properties[i][1]);
        }
        return weakCharacters;
    }
};
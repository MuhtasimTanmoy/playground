// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int left = 0, right = size(matrix) - 1;
//         while(left < right) {
//             auto top = left, bottom = right;
//             for(int i = 0; i < right - left; i++) {
//                 auto topLeft = matrix[top][left+i];
//                 matrix[top][left+i] = matrix[bottom-i][left];
//                 matrix[bottom-i][left] = matrix[bottom][right-i];
//                 matrix[bottom][right-i] = matrix[top+i][right];
//                 matrix[top+i][right] = topLeft;
//             }
//             left++;
//             right--;
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = size(matrix) - 1;
        while (left < right) {
            auto top = left, bottom = right;
            for ( int i = 0; i < (right-left); i++) {
                auto cache = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = cache;
            }
            left++;
            right--;
        }
    }
};




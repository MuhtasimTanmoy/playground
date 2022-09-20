class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int left = 0;
        int right = size(letters) - 1;
        
        while(left <= right) {
            int mid = (left + right) >> 1;
            if (letters[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        if (left == size(letters)) return letters[0];
        else return letters[left];
        
    }
};
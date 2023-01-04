class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[0] >= arr[1]) return false;
        bool goingUp = true;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i-1] == arr[i]) return false;
            if (goingUp) {
                if (arr[i-1] > arr[i]) goingUp = false;
            } else {
                if (arr[i-1] < arr[i]) return false;
            }
        }
        return goingUp == false;
    }
};
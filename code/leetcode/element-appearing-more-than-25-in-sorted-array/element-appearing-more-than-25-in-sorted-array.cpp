class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        if ( arr.size() == 1) { return arr[0]; }
        
        int currentMost = 0;
        int most = 0;
        
        int mostOccured = 0;
        
        for(int i = 1 ; i< arr.size(); i++) {
            if ( arr[i - 1] == arr[i]) {
                currentMost++;
                if (currentMost > most) {
                    most = currentMost;
                    mostOccured = arr[i];
                }
            } else {
                currentMost = 0;
            }
        }
        return mostOccured;
    }
};
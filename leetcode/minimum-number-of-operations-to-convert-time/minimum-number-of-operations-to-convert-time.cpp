class Solution {
public:
    int convertTime(string current, string correct) {
        
        int distanceInMinutes = 0;
        
        distanceInMinutes = (correct[0] - current[0]) * 10 + (correct[1] - current[1]);
        distanceInMinutes *= 60;
        
        distanceInMinutes += (correct[3] - current[3]) * 10 + (correct[4] - current[4]);
        
        int steps = 0;
        
        vector<int> canBeSubstractedArr = { 60, 15, 5, 1};
        
        while (distanceInMinutes) {
            
            for (auto canBeSubstracted :canBeSubstractedArr) {
                if ( distanceInMinutes >= canBeSubstracted ) {
                    distanceInMinutes -= canBeSubstracted;
                    steps++;
                    break;
                }
            }
        }
        
        return steps;
        
        
    }
};
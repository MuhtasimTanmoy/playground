class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int last = 0, maxv = 0;
        char res;
        
        for (int i = 0; i < keysPressed.size(); ++i) {
            int diff = releaseTimes[i] - last;
            
            if (maxv < diff) {
                maxv = diff;
                res = keysPressed[i];
            } else if (maxv == diff && res < keysPressed[i]) 
                res = keysPressed[i];
            
            last = releaseTimes[i];
        }
        return res;
    }
};
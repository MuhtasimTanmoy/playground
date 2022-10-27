class LUPrefix {
public:
    LUPrefix(int n) {
        marker = vector<bool>(n + 1, false);
    }
    
    void upload(int video) {
        marker[video] = true;
    }
    
    int longest() {
        int index = curr;
        while (curr + 1 < marker.size() && marker[curr + 1]) {
            curr++;
            index = curr;
        }
        return index;
    }
private:
    vector<bool> marker;
    int curr = 0;
};
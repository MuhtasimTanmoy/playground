class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        
        int result = 0;
        int index = 0;
        
        while(truckSize && index < size(boxTypes)) {
            int selectedBox = min(truckSize, boxTypes[index][0]);
            cout<<selectedBox<<endl;
            result += selectedBox * boxTypes[index][1];
            truckSize -= selectedBox;
            index++;
        }
        
        return result;
    }
};
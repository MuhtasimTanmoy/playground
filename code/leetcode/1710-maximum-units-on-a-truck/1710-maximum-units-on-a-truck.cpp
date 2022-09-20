class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int>& boxMetaA, 
                                                   const vector<int>& boxMetaB) {
            return boxMetaA[1] > boxMetaB[1];
        });
        
        int res = 0;
        int itr = 0;
        
        while(truckSize && itr < size(boxTypes)) {
            int boxTaking = min(boxTypes[itr][0], truckSize);
            truckSize -= boxTaking;
            res += boxTaking * boxTypes[itr][1];
            itr++;
        }
        return res;
    }
};
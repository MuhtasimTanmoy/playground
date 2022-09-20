class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int boundary = size(arr) / 20;
        
        double sum = 0;
        for( int i = boundary; i < size(arr) - boundary; i++ ) 
            sum += arr[i];
        
        return sum / (size(arr)- 2 * boundary);
    }
};
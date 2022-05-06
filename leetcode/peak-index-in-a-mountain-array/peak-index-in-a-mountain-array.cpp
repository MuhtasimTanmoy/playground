class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = size(arr) - 2;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            cout<<mid<<endl;
            if ( arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] ) return mid;
            
            if ( arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1] ) left = mid + 1;
            else right = mid - 1;
        }
        
        return 1;
    }
};
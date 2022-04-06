class Solution {
public:

    int threeSumMulti(vector<int>& arr, int X) {
        int n = arr.size(), mod = 1e9+7, ans = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) {
            ans = (ans + m[X - arr[i]]) % mod;
            
            for(int j=0; j<i; j++) m[arr[i] + arr[j]]++;
        }
        return ans;
    }
//     int threeSumMulti(vector<int>& arr, int target) {
        
//         int result = 0;
        
//         // TLE
//         // for( int i = 0; i < size(arr) - 2; i++ ) {
//         //     for( int j = i+1; j < size(arr) - 1; j++ ) {
//         //         for( int k = j+1; k < size(arr); k++ ) {
//         //             if (arr[i] + arr[j] + arr[k] == target) result++;
//         //         }
//         //     }
//         // }
        
//         if( arr.size() < 3 ) return 1;
//         sort(arr.begin(), arr.end());
        
//         int l, r;
        
//         for(int i = 0; i < arr.size(); i++) { 
                                    
//           l = i + 1, r = arr.size() - 1;
            
//           while( l < r ) {
              
//             if( arr[i] + arr[l] + arr[r] == target ) {
                
//                 int combi = 0;
                
//                 int leftR = 1;
//                 int rightR = 1;
                
//                 while( l < r && arr[l] == arr[l+1] ) {
//                     leftR++;
//                     l++;
//                 }
                
//                 while( l < r && arr[r] == arr[r-1] ) {
//                     rightR++;
//                     r--;
//                 }
                
//                 result += ( leftR * rightR );
                
//                 l++;
//                 r--;
                
//             } else if( arr[i] + arr[l] + arr[r] > target )
//                 r--;
//              else if( arr[i] + arr[l] + arr[r] < target)
//                 l++;
//             }
//         }
        
//         return result;
//     }
};
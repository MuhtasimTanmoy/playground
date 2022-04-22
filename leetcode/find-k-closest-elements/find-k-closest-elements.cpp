class Solution {
    
    // int binary(vector<int>& arr, int x) {
    //     int start = 0;
    //     int end = size(arr)-1;
    //     while( start < end ) {
    //         int mid = (start+end) >> 1;
    //         if ( arr[mid] == x ) return mid;
    //         else if ( arr[mid] > x ) end = mid - 1;
    //         else { start = mid + 1; };
    //     }
    //     return 0;
    // }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
//         priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
//         for(int i = 0; i < arr.size(); i++) pq.push( {abs(arr[i]-x), arr[i]} );
    
//         vector<int> ans;
//         while(k--) {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
        
//         sort(ans.begin(), ans.end());
//         return ans;
        
         int n = arr.size();
        vector<int> ans;
        
        int cnt = n;
        int l = 0, r = n - 1;
        
        while(l < r && cnt > k) {
            int left_d = abs(arr[l] - x);
            int right_d = abs(arr[r] - x);
            
            if(left_d <= right_d) r--;
            else l++;
            
            cnt--;
        }
        
        for(int i=l; i<=r; ++i) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};
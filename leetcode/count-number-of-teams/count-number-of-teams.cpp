class Solution {
public:
    int numTeams(vector<int>& rating) {
        
//          This one gets TLE
        
//         int res = 0;
//         int n = size(rating);
        
//         for(int i = 0; i < n - 2; i++) {
//            for(int j = i + 1; j < n - 1; j++) {
//                 if (rating[j] <= rating[i]) continue;
//                 for(int k = j + 1; k < n; k++) {
//                     if (rating[k] <= rating[j]) continue;
//                     res++;
//                 }
//             } 
//         }
        
//         for(int i = 0; i < n - 2; i++) {
//            for(int j = i + 1; j < n - 1; j++) {
//                 if (rating[j] >= rating[i]) continue;
//                 for(int k = j + 1; k < n; k++) {
//                     if (rating[k] >= rating[j]) continue;
//                     res++;
//                 }
//             } 
//         }
        
//         return res;
        
        int n = size(rating);
        vector<int> preMax(n);
        vector<int> preMin(n);
        int res = 0;
        
        for(int i = 0; i < n - 1; i++) {
            int count = 0;
            for(int j = i + 1; j < n; j++) if (rating[i] < rating[j]) count++;
            preMax[i] = count;
        }
        
        for(int i = 0; i < n - 1; i++) {
            int count = 0;
            for(int j = i + 1; j < n; j++) if (rating[i] > rating[j]) count++;
            preMin[i] = count;
        }
        
        for(int i = 0; i < n - 2; i++)
           for(int j = i + 1; j < n - 1; j++)
               if (rating[i] > rating[j]) res += preMin[j];
        
        for(int i = 0; i < n - 2; i++)
           for(int j = i + 1; j < n - 1; j++) 
               if (rating[i] < rating[j]) res += preMax[j];
  
        return res;
        
    }
};
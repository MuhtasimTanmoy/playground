class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        
        // can change the dimention to detect bit pattern and add that pattern, the one with excess one will be the answer.
        
        vector<int> bitpattern(32,0);
        for(int num: nums) {
            for( int i = 0; i< 32; i++) {
                if ( num & ( 1 << i ) ) {
                    bitpattern[i] += 1; 
                }
            }
        }
        
        int result = 0;
        for( int i = 0; i< 32; i++) {
            if ( bitpattern[i] % 3 == 1 ) {
                result += ( 1 << i );
            }
        }
        return result;
    }

    // Map based solution
    
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> occurenceCount;
        
//         for(int i: nums) {
//             occurenceCount[i] = occurenceCount[i] + 1;
//         }
        
//         unordered_map<int,int>::iterator occurenceItr;
        
//         for( occurenceItr = occurenceCount.begin();  
//              occurenceItr != occurenceCount.end(); 
//              occurenceItr++ ) {
//              if ( occurenceItr-> second == 1) {
//                  return occurenceItr -> first;
//              }  
//         }
        
//         return 0;
//     }
    
    // Can be sorted. nlogn solution
};

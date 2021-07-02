class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> occurenceCount;
        
        for(int i: nums) {
            occurenceCount[i] = occurenceCount[i] + 1;
        }
        
        unordered_map<int,int>::iterator occurenceItr;
        
        for( occurenceItr = occurenceCount.begin();  
             occurenceItr != occurenceCount.end(); 
             occurenceItr++ ) {
             if ( occurenceItr-> second == 1) {
                 return occurenceItr -> first;
             }  
        }
        
        return 0;
    }
};
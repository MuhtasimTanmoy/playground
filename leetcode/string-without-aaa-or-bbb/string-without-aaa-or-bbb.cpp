class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        int now =  a > b ? 'a' : 'b';
        char prev = ' ';
        
        while(a || b) {
            s += now;
            
            if ( now == 'a' ) a--;
            else b--;
            
            char nextToBe = ' ';
            if (prev == now) {
                nextToBe = now == 'a' ? 'b' : 'a';
            } else {
                nextToBe =  a > b ? 'a' : 'b';
            }
            prev = now;
            now = nextToBe;
        }
        
        return s;
    }
};
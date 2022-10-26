// class ATM {
// public:
//     ATM() {
        
//     }
    
//     void deposit(vector<int> banknotesCount) {
        
//     }
    
//     vector<int> withdraw(int amount) {
        
//     }
// };

// /**
//  * Your ATM object will be instantiated and called as such:
//  * ATM* obj = new ATM();
//  * obj->deposit(banknotesCount);
//  * vector<int> param_2 = obj->withdraw(amount);
//  */

// 111 / 152 test cases passed.
/*
class ATM {
public:
    ATM() { }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) 
            noteToCount[i].second += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        auto len = noteToCount.size();
        vector<int> res(len, 0);
        
        for (int i = len - 1; i >= 0; i--) {
            auto noteVal = noteToCount[i].first;
            auto limit = noteToCount[i].second;
            if (noteVal > amount || !limit) continue;
            
            long long canBeTakenCount = (amount / noteVal);
            long validCount = min(limit, canBeTakenCount);
            amount -= validCount * noteVal;
            res[i] = validCount;
        }
        
        cout<<amount<<endl;
        
        if (amount) return {-1};
        return res;
    }
private:
    vector<pair<int, long long>> 
        noteToCount{{20, 0}, {50, 0}, {100, 0}, {200, 0}, {500, 0}};
};
*/

class ATM {
public:
    long long bank[5] = {}, val[5] = {20, 50, 100, 200, 500};
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            bank[i] += banknotesCount[i];
    }
    vector<int> withdraw(int amount) {
        vector<int> take(5);
        for (int i = 4; i >= 0; --i) {
            take[i] = min(bank[i], amount / val[i]);
            amount -= take[i] * val[i];
        }
        if (amount)
            return { -1 };
        for (int i = 0; i < 5; ++i)
            bank[i] -= take[i];            
        return take;
    }
};
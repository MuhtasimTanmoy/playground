class Bank {
public:
    Bank(vector<long long>& balance): balance(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        if (withdraw(account1, money)) return deposit(account2, money);
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (is_invalid(account)) return false;
        
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (is_invalid(account)) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
private: 
    vector<long long>& balance;
    bool is_invalid(int account) {
        if (account <= 0 || account > balance.size()) return true;
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
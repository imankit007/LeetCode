class Bank {
public:
    Bank(vector<long long>& balance) {
        size = balance.size();
        for (const long long bal : balance) {
            accounts.push_back(bal);
        }
    }

    bool transfer(int account1, int account2, long long money) {

        if (account1 > size || account2 > size) {
            return false;
        }

        long long bal1 = accounts[account1 - 1];
        if (bal1 < money) {
            return false;
        }
        
        return withdraw(account1, money) && deposit(account2, money);
    }

    bool deposit(int account, long long money) {

        if (account > size) {
            return false;
        }

        accounts[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {

        if (account > size) {
            return false;
        }

        if (money > accounts[account - 1]) {
            return false;
        }
        accounts[account - 1] -= money;
        return true;
    }

private:
    vector<long long> accounts;
    int size;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
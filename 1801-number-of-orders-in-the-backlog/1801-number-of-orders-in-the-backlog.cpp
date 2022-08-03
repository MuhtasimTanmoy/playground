// class Solution {
//     int mod = 1000000007;
// public:
//     int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
//         priority_queue<vector<int>> buyorders;
//         priority_queue<vector<int>, vector<vector<int>>, greater<int>> sellorders;
        
//         for (auto order: orders) {
//             auto price = order[0], amount = order[1], orderType = order[2];
//             cout<<price<<"-"<<amount<<"-"<<orderType<<endl;
//             switch (orderType) {
//                 case 0:
//                     while (amount) {
//                         auto sellOrder = sellorders.top();
//                         if (sellOrder[0] <= price) {
//                             if (amount < sellOrder[1]) {
//                                 sellOrder[1] -= amount;
//                                 amount = 0;
//                             } else if (amount > sellOrder[1]) {
//                                 amount -= sellOrder[1];
//                                 if (sellorders.size()) sellorders.pop();
//                             } else {
//                                 amount = 0;
//                                 if (sellorders.size()) sellorders.pop();
//                             }
//                         } else buyorders.push({price, amount, orderType});
//                     }
//                     break;
//                 case 1:
//                     while (amount) {
//                         auto buyOrder = buyorders.top();
//                         if (buyOrder[0] >= price) {
//                             if (amount < buyOrder[1]) {
//                                 buyOrder[1] -= amount;
//                                 amount = 0;
//                             } else if (amount > buyOrder[1]) {
//                                 amount -= buyOrder[1];
//                                 if (buyorders.size()) buyorders.pop();
//                             } else {
//                                 amount = 0;
//                                 if (buyorders.size()) buyorders.pop();
//                             }
//                         } else sellorders.push({price, amount, orderType});
//                     }
//                     break;
//             }
//         }
        
//         int res = 0;
//         while (buyorders.size()) res = (res + buyorders.top()[1]) % mod;
//         while (sellorders.size()) res = (res + sellorders.top()[1]) % mod;
//         return res;
//     }
// };


class Solution {
    int mod = 1000000007;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy, sell;
        long res = 0;
        for (auto &o : orders) {
            res += o[1];
            if (o[2])
                sell.push({-o[0], o[1]});
            else
                buy.push({o[0], o[1]});
            while (!sell.empty() && !buy.empty() && -sell.top().first <= buy.top().first) {
                auto [sell_p, sell_a] = sell.top(); sell.pop();
                auto [buy_p, buy_a] = buy.top(); buy.pop();
                auto execute = min(sell_a, buy_a);
                res -= 2 * execute;
                if (sell_a > execute)
                    sell.push({sell_p, sell_a - execute});
                if (buy_a > execute)
                    buy.push({buy_p, buy_a - execute});   
            }
        }
        return res % 1000000007;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(const int price: prices){
            buy=min(buy, price);
            profit = max(price - buy, profit);
        }
        return profit;
    }
};
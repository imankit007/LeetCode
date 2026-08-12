class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int c1 = INT_MAX;
        int c2 = INT_MAX;

        for(const int price : prices){
            if(price<c1){
                c2 =c1;
                c1 = price;
            }else if(price<c2){
                c2 = price;
            }
        }

        return money-c1-c2>=0 ? money - c1 -c2 : money;
    }
};
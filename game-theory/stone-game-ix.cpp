class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3);


        for(const int &n : stones ){
            ++count[n % 3];
        }

        if(count[0] % 2 == 0){
            return min(count[1], count[2]) > 0;
        }

        return abs(count[2]-count[1]) > 2;

    }
};
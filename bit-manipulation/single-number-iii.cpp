class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long long cors = 0;
        for(const int num :nums){
            cors^=num;
        }

        int last_bit = cors & -cors;
        int num1 = 0;
        for(const int num: nums){
            if(num & last_bit){
                num1^=num;
            }
        }

        int num2 = cors^num1;
        return {num1, num2};

    }
};
class Solution {
public:
    string largestGoodInteger(string num) {
        const int n = num.size();

        int ans = INT_MIN;

        for(int i = 0; i< n -2; ++i){
            if(num[i]  == num[i+1] && num [i]==num[i +2]){
                ans = max(ans, stoi(num.substr(i,3)));
            }
        }

        if(ans == INT_MIN){
            return "";
        }

        return ans ==0 ? "000" : to_string(ans);
    }
};